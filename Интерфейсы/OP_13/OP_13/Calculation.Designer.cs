using System.Windows.Forms;

namespace OP_13
{
    partial class Calculation
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            this.label1_reporting_period = new System.Windows.Forms.Label();
            this.label2_reporting_period = new System.Windows.Forms.Label();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.dGV_Calculation = new System.Windows.Forms.DataGridView();
            this.Name_ = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Code = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.balance_start = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.balance_receipt = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.balance_end = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cost = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dateTimePicker2 = new System.Windows.Forms.DateTimePicker();
            this.dateTimePicker3 = new System.Windows.Forms.DateTimePicker();
            this.button_cancel = new System.Windows.Forms.Button();
            this.button_save = new System.Windows.Forms.Button();
            this.calculate = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxOKPO = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxOKDP = new System.Windows.Forms.TextBox();
            this.textBoxNumberDoc = new System.Windows.Forms.TextBox();
            this.comboBoxOrganization = new System.Windows.Forms.ComboBox();
            this.comboBoxStructSubdivision = new System.Windows.Forms.ComboBox();
            this.dGV_Spravka = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.NumberDishes = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Summa = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.label11 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxRubl1 = new System.Windows.Forms.TextBox();
            this.textBoxCopeica1 = new System.Windows.Forms.TextBox();
            this.textBoxCopeica2 = new System.Windows.Forms.TextBox();
            this.textBoxRubl2 = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.linkLabelSignatures = new System.Windows.Forms.LinkLabel();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Calculation)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Spravka)).BeginInit();
            this.SuspendLayout();
            // 
            // label1_reporting_period
            // 
            this.label1_reporting_period.AutoSize = true;
            this.label1_reporting_period.Location = new System.Drawing.Point(64, 49);
            this.label1_reporting_period.Name = "label1_reporting_period";
            this.label1_reporting_period.Size = new System.Drawing.Size(104, 13);
            this.label1_reporting_period.TabIndex = 2;
            this.label1_reporting_period.Text = "Отчётный период с";
            // 
            // label2_reporting_period
            // 
            this.label2_reporting_period.AutoSize = true;
            this.label2_reporting_period.Location = new System.Drawing.Point(321, 49);
            this.label2_reporting_period.Name = "label2_reporting_period";
            this.label2_reporting_period.Size = new System.Drawing.Size(19, 13);
            this.label2_reporting_period.TabIndex = 3;
            this.label2_reporting_period.Text = "по";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(668, 46);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(141, 20);
            this.dateTimePicker1.TabIndex = 4;
            // 
            // dGV_Calculation
            // 
            this.dGV_Calculation.AllowUserToAddRows = false;
            this.dGV_Calculation.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.TopCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dGV_Calculation.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dGV_Calculation.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Calculation.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Name_,
            this.Code,
            this.balance_start,
            this.balance_receipt,
            this.balance_end,
            this.cost});
            this.dGV_Calculation.GridColor = System.Drawing.SystemColors.Control;
            this.dGV_Calculation.Location = new System.Drawing.Point(16, 124);
            this.dGV_Calculation.Name = "dGV_Calculation";
            this.dGV_Calculation.Size = new System.Drawing.Size(793, 244);
            this.dGV_Calculation.TabIndex = 7;
            // 
            // Name_
            // 
            this.Name_.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.Name_.Frozen = true;
            this.Name_.HeaderText = "Наименование";
            this.Name_.Name = "Name_";
            this.Name_.Width = 108;
            // 
            // Code
            // 
            this.Code.Frozen = true;
            this.Code.HeaderText = "Код";
            this.Code.Name = "Code";
            this.Code.Width = 40;
            // 
            // balance_start
            // 
            this.balance_start.HeaderText = "Остаток на начало отчётного периода (сумма), руб.коп.";
            this.balance_start.Name = "balance_start";
            this.balance_start.Width = 150;
            // 
            // balance_receipt
            // 
            this.balance_receipt.HeaderText = "Поступило за отчётный период (сумма), руб.коп.";
            this.balance_receipt.Name = "balance_receipt";
            this.balance_receipt.Width = 150;
            // 
            // balance_end
            // 
            this.balance_end.HeaderText = "Остаток на конец отчётного периода (сумма), руб.коп.";
            this.balance_end.Name = "balance_end";
            this.balance_end.Width = 150;
            // 
            // cost
            // 
            this.cost.HeaderText = "Израсходовано за отчётный период (сумма), руб.коп.";
            this.cost.Name = "cost";
            this.cost.Width = 150;
            // 
            // dateTimePicker2
            // 
            this.dateTimePicker2.Location = new System.Drawing.Point(174, 46);
            this.dateTimePicker2.Name = "dateTimePicker2";
            this.dateTimePicker2.Size = new System.Drawing.Size(141, 20);
            this.dateTimePicker2.TabIndex = 2;
            // 
            // dateTimePicker3
            // 
            this.dateTimePicker3.Location = new System.Drawing.Point(346, 46);
            this.dateTimePicker3.Name = "dateTimePicker3";
            this.dateTimePicker3.Size = new System.Drawing.Size(140, 20);
            this.dateTimePicker3.TabIndex = 3;
            // 
            // button_cancel
            // 
            this.button_cancel.Location = new System.Drawing.Point(734, 659);
            this.button_cancel.Name = "button_cancel";
            this.button_cancel.Size = new System.Drawing.Size(75, 23);
            this.button_cancel.TabIndex = 15;
            this.button_cancel.Text = "Отмена";
            this.button_cancel.UseVisualStyleBackColor = true;
            this.button_cancel.Click += new System.EventHandler(this.button_cancel_Click);
            // 
            // button_save
            // 
            this.button_save.Location = new System.Drawing.Point(654, 659);
            this.button_save.Name = "button_save";
            this.button_save.Size = new System.Drawing.Size(75, 23);
            this.button_save.TabIndex = 14;
            this.button_save.Text = "Сохранить";
            this.button_save.UseVisualStyleBackColor = true;
            this.button_save.Click += new System.EventHandler(this.button_save_Click);
            // 
            // calculate
            // 
            this.calculate.Location = new System.Drawing.Point(654, 632);
            this.calculate.Name = "calculate";
            this.calculate.Size = new System.Drawing.Size(156, 21);
            this.calculate.TabIndex = 12;
            this.calculate.Text = "Рассчитать";
            this.calculate.UseVisualStyleBackColor = true;
            this.calculate.Click += new System.EventHandler(this.calculate_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(94, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Организация";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 102);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(151, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Структурное подразделение";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(569, 101);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(93, 13);
            this.label4.TabIndex = 17;
            this.label4.Text = "Форма по ОКПО";
            // 
            // textBoxOKPO
            // 
            this.textBoxOKPO.Location = new System.Drawing.Point(668, 98);
            this.textBoxOKPO.Name = "textBoxOKPO";
            this.textBoxOKPO.Size = new System.Drawing.Size(141, 20);
            this.textBoxOKPO.TabIndex = 101;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(510, 76);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(152, 13);
            this.label5.TabIndex = 19;
            this.label5.Text = "Вид деятельности  по ОКДП";
            // 
            // textBoxOKDP
            // 
            this.textBoxOKDP.Location = new System.Drawing.Point(668, 73);
            this.textBoxOKDP.Name = "textBoxOKDP";
            this.textBoxOKDP.Size = new System.Drawing.Size(141, 20);
            this.textBoxOKDP.TabIndex = 71;
            // 
            // textBoxNumberDoc
            // 
            this.textBoxNumberDoc.Location = new System.Drawing.Point(392, 14);
            this.textBoxNumberDoc.Name = "textBoxNumberDoc";
            this.textBoxNumberDoc.Size = new System.Drawing.Size(82, 20);
            this.textBoxNumberDoc.TabIndex = 1;
            // 
            // comboBoxOrganization
            // 
            this.comboBoxOrganization.FormattingEnabled = true;
            this.comboBoxOrganization.Items.AddRange(new object[] {
            "Организация 1",
            "Организация 2",
            "Организация 3"});
            this.comboBoxOrganization.Location = new System.Drawing.Point(174, 72);
            this.comboBoxOrganization.Name = "comboBoxOrganization";
            this.comboBoxOrganization.Size = new System.Drawing.Size(312, 21);
            this.comboBoxOrganization.TabIndex = 5;
            // 
            // comboBoxStructSubdivision
            // 
            this.comboBoxStructSubdivision.FormattingEnabled = true;
            this.comboBoxStructSubdivision.Items.AddRange(new object[] {
            "Подразделение 1",
            "Подразделение 2",
            "Подразделение 3"});
            this.comboBoxStructSubdivision.Location = new System.Drawing.Point(174, 97);
            this.comboBoxStructSubdivision.Name = "comboBoxStructSubdivision";
            this.comboBoxStructSubdivision.Size = new System.Drawing.Size(312, 21);
            this.comboBoxStructSubdivision.TabIndex = 6;
            // 
            // dGV_Spravka
            // 
            this.dGV_Spravka.AllowUserToAddRows = false;
            this.dGV_Spravka.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.TopCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dGV_Spravka.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.dGV_Spravka.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGV_Spravka.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.NumberDishes,
            this.Summa});
            this.dGV_Spravka.Location = new System.Drawing.Point(16, 476);
            this.dGV_Spravka.Name = "dGV_Spravka";
            this.dGV_Spravka.Size = new System.Drawing.Size(793, 150);
            this.dGV_Spravka.TabIndex = 12;
            // 
            // Column1
            // 
            this.Column1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.AllCells;
            this.Column1.HeaderText = "";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            this.Column1.Width = 19;
            // 
            // NumberDishes
            // 
            this.NumberDishes.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.NumberDishes.HeaderText = "Количество блюд";
            this.NumberDishes.Name = "NumberDishes";
            // 
            // Summa
            // 
            this.Summa.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Summa.HeaderText = "Сумма (руб.коп.)";
            this.Summa.Name = "Summa";
            this.Summa.ReadOnly = true;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label11.Location = new System.Drawing.Point(120, 381);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(568, 18);
            this.label11.TabIndex = 36;
            this.label11.Text = "Справка о стоимости специй и соли, включенной в калькуляцию блюд";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 412);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(151, 13);
            this.label1.TabIndex = 37;
            this.label1.Text = "Стоимость специй на блюдо";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(262, 412);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(27, 13);
            this.label6.TabIndex = 38;
            this.label6.Text = "руб.";
            // 
            // textBoxRubl1
            // 
            this.textBoxRubl1.Location = new System.Drawing.Point(174, 409);
            this.textBoxRubl1.Name = "textBoxRubl1";
            this.textBoxRubl1.Size = new System.Drawing.Size(82, 20);
            this.textBoxRubl1.TabIndex = 8;
            // 
            // textBoxCopeica1
            // 
            this.textBoxCopeica1.Location = new System.Drawing.Point(295, 409);
            this.textBoxCopeica1.Name = "textBoxCopeica1";
            this.textBoxCopeica1.Size = new System.Drawing.Size(82, 20);
            this.textBoxCopeica1.TabIndex = 9;
            // 
            // textBoxCopeica2
            // 
            this.textBoxCopeica2.Location = new System.Drawing.Point(295, 441);
            this.textBoxCopeica2.Name = "textBoxCopeica2";
            this.textBoxCopeica2.Size = new System.Drawing.Size(82, 20);
            this.textBoxCopeica2.TabIndex = 11;
            // 
            // textBoxRubl2
            // 
            this.textBoxRubl2.Location = new System.Drawing.Point(174, 441);
            this.textBoxRubl2.Name = "textBoxRubl2";
            this.textBoxRubl2.Size = new System.Drawing.Size(82, 20);
            this.textBoxRubl2.TabIndex = 10;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(383, 444);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(28, 13);
            this.label12.TabIndex = 44;
            this.label12.Text = "коп.";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(262, 444);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(27, 13);
            this.label13.TabIndex = 43;
            this.label13.Text = "руб.";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(17, 444);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(139, 13);
            this.label14.TabIndex = 42;
            this.label14.Text = "Стоимость соли на блюдо";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(627, 49);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(33, 13);
            this.label8.TabIndex = 46;
            this.label8.Text = "Дата";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(178, 14);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(208, 20);
            this.label9.TabIndex = 47;
            this.label9.Text = "Контрольный расчет №";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label10.Location = new System.Drawing.Point(480, 14);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(202, 20);
            this.label10.TabIndex = 48;
            this.label10.Text = "расхода специй и соли";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(383, 412);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(28, 13);
            this.label7.TabIndex = 49;
            this.label7.Text = "коп.";
            // 
            // linkLabelSignatures
            // 
            this.linkLabelSignatures.AutoSize = true;
            this.linkLabelSignatures.Location = new System.Drawing.Point(17, 636);
            this.linkLabelSignatures.Name = "linkLabelSignatures";
            this.linkLabelSignatures.Size = new System.Drawing.Size(123, 13);
            this.linkLabelSignatures.TabIndex = 13;
            this.linkLabelSignatures.TabStop = true;
            this.linkLabelSignatures.Text = "Расшифрока подписей";
            this.linkLabelSignatures.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabelSignatures_LinkClicked);
            // 
            // Calculation
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(822, 688);
            this.Controls.Add(this.linkLabelSignatures);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.textBoxCopeica2);
            this.Controls.Add(this.textBoxRubl2);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.textBoxCopeica1);
            this.Controls.Add(this.textBoxRubl1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.dGV_Spravka);
            this.Controls.Add(this.comboBoxStructSubdivision);
            this.Controls.Add(this.comboBoxOrganization);
            this.Controls.Add(this.textBoxNumberDoc);
            this.Controls.Add(this.textBoxOKDP);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBoxOKPO);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.calculate);
            this.Controls.Add(this.button_save);
            this.Controls.Add(this.button_cancel);
            this.Controls.Add(this.dateTimePicker3);
            this.Controls.Add(this.dateTimePicker2);
            this.Controls.Add(this.dGV_Calculation);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.label2_reporting_period);
            this.Controls.Add(this.label1_reporting_period);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "Calculation";
            this.Text = "ФОРМА ОП-13";
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Calculation)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dGV_Spravka)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1_reporting_period;
        private System.Windows.Forms.Label label2_reporting_period;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.DataGridView dGV_Calculation;
        private System.Windows.Forms.DateTimePicker dateTimePicker2;
        private System.Windows.Forms.DateTimePicker dateTimePicker3;
        private System.Windows.Forms.Button button_cancel;
        private System.Windows.Forms.Button button_save;
        private System.Windows.Forms.Button calculate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private Label label4;
        private TextBox textBoxOKPO;
        private Label label5;
        private TextBox textBoxOKDP;
        private TextBox textBoxNumberDoc;
        private ComboBox comboBoxOrganization;
        private ComboBox comboBoxStructSubdivision;
        private DataGridView dGV_Spravka;
        private Label label11;
        private Label label1;
        private Label label6;
        private TextBox textBoxRubl1;
        private TextBox textBoxCopeica1;
        private TextBox textBoxCopeica2;
        private TextBox textBoxRubl2;
        private Label label12;
        private Label label13;
        private Label label14;
        private DataGridViewTextBoxColumn Column1;
        private DataGridViewTextBoxColumn NumberDishes;
        private DataGridViewTextBoxColumn Summa;
        private DataGridViewTextBoxColumn Name_;
        private DataGridViewTextBoxColumn Code;
        private DataGridViewTextBoxColumn balance_start;
        private DataGridViewTextBoxColumn balance_receipt;
        private DataGridViewTextBoxColumn balance_end;
        private DataGridViewTextBoxColumn cost;
        private Label label8;
        private Label label9;
        private Label label10;
        private Label label7;
        private LinkLabel linkLabelSignatures;
    }
}

