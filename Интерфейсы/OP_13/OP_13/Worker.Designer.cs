namespace OP_13
{
    partial class Worker
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.comboBoxMade = new System.Windows.Forms.ComboBox();
            this.comboBoxApproved = new System.Windows.Forms.ComboBox();
            this.comboBoxAccountant = new System.Windows.Forms.ComboBox();
            this.textBoxMade = new System.Windows.Forms.TextBox();
            this.textBoxApproved = new System.Windows.Forms.TextBox();
            this.textBoxAccountant = new System.Windows.Forms.TextBox();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // comboBoxMade
            // 
            this.comboBoxMade.FormattingEnabled = true;
            this.comboBoxMade.Items.AddRange(new object[] {
            "Бухгалтер",
            "Директор",
            "Заведующий",
            "Повар"});
            this.comboBoxMade.Location = new System.Drawing.Point(12, 39);
            this.comboBoxMade.Name = "comboBoxMade";
            this.comboBoxMade.Size = new System.Drawing.Size(168, 21);
            this.comboBoxMade.TabIndex = 1;
            this.comboBoxMade.Text = "Расчёт и справку составил";
            // 
            // comboBoxApproved
            // 
            this.comboBoxApproved.FormattingEnabled = true;
            this.comboBoxApproved.Items.AddRange(new object[] {
            "Гендиректор",
            "Замдиректора"});
            this.comboBoxApproved.Location = new System.Drawing.Point(12, 66);
            this.comboBoxApproved.Name = "comboBoxApproved";
            this.comboBoxApproved.Size = new System.Drawing.Size(168, 21);
            this.comboBoxApproved.TabIndex = 3;
            this.comboBoxApproved.Text = "Утвердил";
            // 
            // comboBoxAccountant
            // 
            this.comboBoxAccountant.FormattingEnabled = true;
            this.comboBoxAccountant.Items.AddRange(new object[] {
            "Бухгалтер"});
            this.comboBoxAccountant.Location = new System.Drawing.Point(12, 93);
            this.comboBoxAccountant.Name = "comboBoxAccountant";
            this.comboBoxAccountant.Size = new System.Drawing.Size(168, 21);
            this.comboBoxAccountant.TabIndex = 5;
            this.comboBoxAccountant.Text = "Бухгалтер";
            // 
            // textBoxMade
            // 
            this.textBoxMade.Location = new System.Drawing.Point(186, 39);
            this.textBoxMade.Name = "textBoxMade";
            this.textBoxMade.Size = new System.Drawing.Size(180, 20);
            this.textBoxMade.TabIndex = 2;
            // 
            // textBoxApproved
            // 
            this.textBoxApproved.Location = new System.Drawing.Point(186, 67);
            this.textBoxApproved.Name = "textBoxApproved";
            this.textBoxApproved.Size = new System.Drawing.Size(180, 20);
            this.textBoxApproved.TabIndex = 4;
            // 
            // textBoxAccountant
            // 
            this.textBoxAccountant.Location = new System.Drawing.Point(186, 94);
            this.textBoxAccountant.Name = "textBoxAccountant";
            this.textBoxAccountant.Size = new System.Drawing.Size(180, 20);
            this.textBoxAccountant.TabIndex = 6;
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(210, 120);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(75, 23);
            this.buttonSave.TabIndex = 7;
            this.buttonSave.Text = "Сохранить";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(291, 120);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(75, 23);
            this.buttonCancel.TabIndex = 8;
            this.buttonCancel.Text = "Отмена";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // Worker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(378, 152);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.textBoxAccountant);
            this.Controls.Add(this.textBoxApproved);
            this.Controls.Add(this.textBoxMade);
            this.Controls.Add(this.comboBoxAccountant);
            this.Controls.Add(this.comboBoxApproved);
            this.Controls.Add(this.comboBoxMade);
            this.Name = "Worker";
            this.Text = "Расшифровка подписей";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBoxMade;
        private System.Windows.Forms.ComboBox comboBoxApproved;
        private System.Windows.Forms.ComboBox comboBoxAccountant;
        private System.Windows.Forms.TextBox textBoxMade;
        private System.Windows.Forms.TextBox textBoxApproved;
        private System.Windows.Forms.TextBox textBoxAccountant;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonCancel;
    }
}