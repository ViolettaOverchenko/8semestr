namespace SpamFilter
{
    partial class SpamFilterForms
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.inbox = new System.Windows.Forms.Button();
            this.spam = new System.Windows.Forms.Button();
            this.GetLetters = new System.Windows.Forms.Button();
            this.Column1Sender = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2MessageSubject = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3Text = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.ScrollBar;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1Sender,
            this.Column2MessageSubject,
            this.Column3Text});
            this.dataGridView1.Location = new System.Drawing.Point(112, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(555, 169);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // inbox
            // 
            this.inbox.Location = new System.Drawing.Point(12, 12);
            this.inbox.Name = "inbox";
            this.inbox.Size = new System.Drawing.Size(94, 32);
            this.inbox.TabIndex = 1;
            this.inbox.Text = "Входящие";
            this.inbox.UseVisualStyleBackColor = true;
            this.inbox.Click += new System.EventHandler(this.inbox_Click);
            // 
            // spam
            // 
            this.spam.Location = new System.Drawing.Point(12, 50);
            this.spam.Name = "spam";
            this.spam.Size = new System.Drawing.Size(94, 30);
            this.spam.TabIndex = 2;
            this.spam.Text = "Спам";
            this.spam.UseVisualStyleBackColor = true;
            this.spam.Click += new System.EventHandler(this.spam_Click);
            // 
            // GetLetters
            // 
            this.GetLetters.Location = new System.Drawing.Point(551, 187);
            this.GetLetters.Name = "GetLetters";
            this.GetLetters.Size = new System.Drawing.Size(116, 32);
            this.GetLetters.TabIndex = 3;
            this.GetLetters.Text = "Получить письмо";
            this.GetLetters.UseVisualStyleBackColor = true;
            this.GetLetters.Click += new System.EventHandler(this.GetLetters_Click);
            // 
            // Column1Sender
            // 
            this.Column1Sender.HeaderText = "Отправитель";
            this.Column1Sender.Name = "Column1Sender";
            this.Column1Sender.ReadOnly = true;
            // 
            // Column2MessageSubject
            // 
            this.Column2MessageSubject.HeaderText = "Тема письма";
            this.Column2MessageSubject.Name = "Column2MessageSubject";
            this.Column2MessageSubject.ReadOnly = true;
            // 
            // Column3Text
            // 
            this.Column3Text.HeaderText = "Текст сообщения";
            this.Column3Text.Name = "Column3Text";
            this.Column3Text.ReadOnly = true;
            this.Column3Text.Width = 310;
            // 
            // SpamFilterForms
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(680, 226);
            this.Controls.Add(this.GetLetters);
            this.Controls.Add(this.spam);
            this.Controls.Add(this.inbox);
            this.Controls.Add(this.dataGridView1);
            this.Name = "SpamFilterForms";
            this.Text = "Спам-фильтр";
            this.Load += new System.EventHandler(this.SpamFilterForms_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button inbox;
        private System.Windows.Forms.Button spam;
        private System.Windows.Forms.Button GetLetters;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1Sender;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2MessageSubject;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3Text;
    }
}

