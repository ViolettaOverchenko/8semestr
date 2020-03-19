using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Excel = Microsoft.Office.Interop.Excel;
using System.IO;

namespace OP_13
{
    public partial class Worker : Form
    {
        public Worker()
        {
            InitializeComponent();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            string fileName = Application.StartupPath + "\\" + "op13" + ".xlsx",
                fileName_new = Application.StartupPath + "\\" + "time_op13_new" + ".xlsx";

            Excel.Application exApp = new Excel.Application();
            //Получаем набор ссылок на объекты Workbook
            Excel.Workbook excelappworkbooks = exApp.Workbooks.Open(fileName,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing, Type.Missing, Type.Missing,
              Type.Missing, Type.Missing);

            // Получить первый рабочий лист.
            Excel.Worksheet excelsheets = (Excel.Worksheet)excelappworkbooks.Sheets[1];

            //заполняем строку
            excelsheets.Cells[49, "P"] = comboBoxMade.Text;
            excelsheets.Cells[49, "AH"] = textBoxMade.Text;
            excelsheets.Cells[13, "AR"] = comboBoxApproved.Text;
            excelsheets.Cells[15, "AS"] = textBoxApproved.Text;
            excelsheets.Cells[51, "P"] = textBoxAccountant.Text;

            //Save to file
            excelsheets.SaveAs(fileName_new);

            exApp.Quit();
            this.Close();
        }

        private void Worker_Load(object sender, EventArgs e)
        {
            string path = Application.StartupPath + "\\" + "time_op13_new" + ".xlsx";
            FileInfo fileInf = new FileInfo(path);
            if (fileInf.Exists)
            {
                fileInf.Delete();
            }
        }
    }
}
