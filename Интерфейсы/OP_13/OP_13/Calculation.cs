using System;
using System.Collections.Generic;
using System.ComponentModel;
using SD = System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Excel = Microsoft.Office.Interop.Excel;
using System.IO;

namespace OP_13
{
    public partial class Calculation : Form
    {
        Worker worker = new Worker();
        public Calculation()
        {
            InitializeComponent();

            // Добавление строк в таблицу
            for(int i = 0; i < 8; ++i)
            {
                dGV_Calculation.Rows.Add();
            }
            dGV_Calculation.Rows[0].Cells[0].Value = "Соль";
            dGV_Calculation.Rows[1].Cells[0].Value = "Перец";
            dGV_Calculation.Rows[2].Cells[0].Value = "Горчица";
            dGV_Calculation.Rows[7].Cells[1].Value = "Итого";
            
            // Нумерация строк в таблице
            for (int i = 0; i < dGV_Calculation.RowCount; i++)
            {
                dGV_Calculation.Rows[i].HeaderCell.Value = (i + 1).ToString(); 
            }

            // Добавление строк в таблицу
            for (int i = 0; i < 5; ++i)
            {
                dGV_Spravka.Rows.Add();
            }
            // Запрещаем изменять определенные ячейки в основной форме
            dGV_Calculation.Rows[7].ReadOnly = true;
            for (int i = 0; i < 3; i++)
            {
                dGV_Calculation.Rows[i].Cells[0].ReadOnly = true;
            }
            // Запрещаем изменять определенные ячейки в справке
            for (int i = 2; i < dGV_Spravka.RowCount; i++)
            {
                dGV_Spravka.Rows[i].Cells[1].ReadOnly = true;
            }
            //Меняем цвет ячейки
            dGV_Spravka.Rows[2].Cells[0].Style.BackColor = Color.LightGray;
            dGV_Spravka.Rows[3].Cells[0].Style.BackColor = Color.LightGray;
            dGV_Spravka.Rows[4].Cells[0].Style.BackColor = Color.LightGray;

            // Заполнение полей таблицы "Справка"
            dGV_Spravka.Rows[0].Cells[0].Value = "Продано блюд, в которые включена стоимость специй на блюдо";
            dGV_Spravka.Rows[1].Cells[0].Value = "Продано блюд, в которые включена стоимость соли на блюдо";
            dGV_Spravka.Rows[2].Cells[0].Value = "Итого";
            dGV_Spravka.Rows[3].Cells[0].Value = "Израсходовано согласно контрольному расчету";
            dGV_Spravka.Rows[4].Cells[0].Value = "Сумма недорасхода";
        }

        private void button_cancel_Click(object sender, EventArgs e)
        {
            string path = Application.StartupPath + "\\" + "time_op13_new" + ".xlsx";
            FileInfo fileInf = new FileInfo(path);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
            this.Close();
        }


        private void linkLabelSignatures_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            worker.Show();
        }

        private void calculate_Click(object sender, EventArgs e)
        {
            // Если какие-то строки заполнены частично, то пустые ячейки этих строк заполняем нулём
            int i = 0;
            for (i = 0; i < dGV_Calculation.Rows.Count - 1; i++)
            {
                if (dGV_Calculation.Rows[i].Cells[0].Value == null)
                {
                    for (int k = 0; k <= 5; k++)
                        dGV_Calculation.Rows[i].Cells[k].Value = null;
                }
                else
                {
                    for (int k = 2; k <= 5; k++)
                        if (dGV_Calculation.Rows[i].Cells[k].Value == null)
                        {
                            dGV_Calculation.Rows[i].Cells[k].Value = "0";
                        }

                }
            }                

            // Считаем ИТОГО 
            for (int j = 2; j < dGV_Calculation.ColumnCount; j++)
            {
                float summa = 0;
                
                for (i = 0; i < dGV_Calculation.Rows.Count-1; i++)
                    if (dGV_Calculation.Rows[i].Cells[j].Value != null)
                    {   
                        float value = Convert.ToSingle(dGV_Calculation.Rows[i].Cells[j].Value);
                        summa += value;
                    }
                dGV_Calculation.Rows[i].Cells[j].Value = summa;
            }

            // Заполняем справку
            
            // Израсходовано согласно контр. расчёта берем из первой таблицы
            dGV_Spravka.Rows[3].Cells[2].Value = dGV_Calculation.Rows[7].Cells[5].Value;
            // Сумма = количество * на цену
            dGV_Spravka.Rows[0].Cells[2].Value = Convert.ToSingle(dGV_Spravka.Rows[0].Cells[1].Value) * 
                (Convert.ToSingle(textBoxRubl1.Text) + Convert.ToSingle(textBoxCopeica1.Text) * 0.01);
            dGV_Spravka.Rows[1].Cells[2].Value = Convert.ToSingle(dGV_Spravka.Rows[1].Cells[1].Value) *
                (Convert.ToSingle(textBoxRubl2.Text) + Convert.ToSingle(textBoxCopeica2.Text) * 0.01);
            // Итого
            dGV_Spravka.Rows[2].Cells[2].Value = Convert.ToSingle(dGV_Spravka.Rows[0].Cells[2].Value) +
               Convert.ToSingle(dGV_Spravka.Rows[1].Cells[2].Value);
            // сумма недорасхода
            dGV_Spravka.Rows[4].Cells[2].Value = Convert.ToSingle(dGV_Spravka.Rows[2].Cells[2].Value) -
              Convert.ToSingle(dGV_Spravka.Rows[3].Cells[2].Value);

        }

        private void ExportToExcel()
        {
            Excel.Application exApp = new Excel.Application();

            //Если временный файл существует, открываем его, если нет, то сразу сохранянем в новую справку
            string fileName = Application.StartupPath + "\\" + "time_op13_new" + ".xlsx";
            //fileName_new = Application.StartupPath + "\\" + "op13_new" + ".xlsx";
            FileInfo fileInf = new FileInfo(fileName);
            if (!fileInf.Exists)
            {
                fileName = Application.StartupPath + "\\" + "op13" + ".xlsx";
            }            
            
            //Получаем набор ссылок на объекты Workbook
            Excel.Workbook excelappworkbooks = exApp.Workbooks.Open(fileName,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing);

            // Получить первый рабочий лист.
            Excel.Worksheet excelsheets = (Excel.Worksheet)excelappworkbooks.Sheets[1];
            
            //заполняем шапку
            excelsheets.Cells[16, "Q"] = textBoxNumberDoc.Text;
            excelsheets.Cells[16, "AC"] = dateTimePicker2.Text;
            excelsheets.Cells[16, "AG"] = dateTimePicker3.Text;
            excelsheets.Cells[16, "W"] = dateTimePicker1.Text;
            excelsheets.Cells[6, "A"] = comboBoxOrganization.Text;
            excelsheets.Cells[8, "A"] = comboBoxStructSubdivision.Text;
            
            if (comboBoxOrganization.Text == "Организация 1")
                excelsheets.Cells[6, "AQ"] = 1;
            if (comboBoxOrganization.Text == "Организация 2")
                excelsheets.Cells[6, "AQ"] = 2;
            if (comboBoxOrganization.Text == "Организация 3")
                excelsheets.Cells[6, "AQ"] = 3;
            if (comboBoxStructSubdivision.Text == "Подразделение 1")
                excelsheets.Cells[9, "AQ"] = 1.1;
            if(comboBoxStructSubdivision.Text == "Подразделение 2")
                excelsheets.Cells[9, "AQ"] = 2.2;
            // заполняем данные из datagridview
            for(int i = 0, k = 25; i < dGV_Calculation.Rows.Count; i++, k++)
            {
                if (dGV_Calculation.Rows[i].Cells[0].Value != null)
                {
                    excelsheets.Cells[k, "E"] = dGV_Calculation.Rows[i].Cells[0].Value;
                    excelsheets.Cells[k, "S"] = dGV_Calculation.Rows[i].Cells[1].Value;
                    excelsheets.Cells[k, "W"] = dGV_Calculation.Rows[i].Cells[2].Value;
                    excelsheets.Cells[k, "AD"] = dGV_Calculation.Rows[i].Cells[3].Value;
                    excelsheets.Cells[k, "AK"] = dGV_Calculation.Rows[i].Cells[4].Value;
                    excelsheets.Cells[k, "AS"] = dGV_Calculation.Rows[i].Cells[5].Value;
                }
            }
            excelsheets.Cells[32, "W"] = dGV_Calculation.Rows[7].Cells[2].Value;
            excelsheets.Cells[32, "AD"] = dGV_Calculation.Rows[7].Cells[3].Value;
            excelsheets.Cells[32, "AK"] = dGV_Calculation.Rows[7].Cells[4].Value;
            excelsheets.Cells[32, "AS"] = dGV_Calculation.Rows[7].Cells[5].Value;

            // заполняем справку из datagridview и textBox
            excelsheets.Cells[40, "C"] = textBoxRubl1.Text;
            excelsheets.Cells[40, "T"] = textBoxCopeica1.Text;
            excelsheets.Cells[43, "C"] = textBoxRubl2.Text;
            excelsheets.Cells[43, "T"] = textBoxCopeica2.Text;
            excelsheets.Cells[39, "AE"] = dGV_Spravka.Rows[0].Cells[1].Value;
            excelsheets.Cells[39, "AL"] = dGV_Spravka.Rows[0].Cells[2].Value;
            excelsheets.Cells[42, "AE"] = dGV_Spravka.Rows[1].Cells[1].Value;
            excelsheets.Cells[42, "AL"] = dGV_Spravka.Rows[1].Cells[2].Value;
            excelsheets.Cells[45, "AE"] = dGV_Spravka.Rows[2].Cells[1].Value;
            excelsheets.Cells[45, "AL"] = dGV_Spravka.Rows[2].Cells[2].Value;
            excelsheets.Cells[46, "AE"] = dGV_Spravka.Rows[3].Cells[1].Value;
            excelsheets.Cells[46, "AL"] = dGV_Spravka.Rows[3].Cells[2].Value;
            excelsheets.Cells[47, "AE"] = dGV_Spravka.Rows[4].Cells[1].Value;
            excelsheets.Cells[47, "AL"] = dGV_Spravka.Rows[4].Cells[2].Value;


            string fileName_new = String.Empty;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "xls files (*.xlsx)|*.xlsx|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                fileName_new = saveFileDialog1.FileName;
            }
            else
                return;

            //сохраняем Workbook
            fileInf = new FileInfo(fileName_new);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
            excelappworkbooks.SaveAs(fileName_new, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Excel.XlSaveAsAccessMode.xlExclusive, Type.Missing, Type.Missing, Type.Missing, Type.Missing);
            saveFileDialog1.Dispose();

            exApp.Quit();
        }

        private void button_save_Click(object sender, EventArgs e)
        {
            calculate_Click(sender, e);
            ExportToExcel();
            string path = Application.StartupPath + "\\" + "time_op13_new" + ".xlsx";
            FileInfo fileInf = new FileInfo(path);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
        }

    }
}
