namespace WindowsFormsApplication5
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
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
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label_addtr = new System.Windows.Forms.Label();
            this.textBox_addtr = new System.Windows.Forms.TextBox();
            this.button_addtr = new System.Windows.Forms.Button();
            this.button_check = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label_addtr
            // 
            this.label_addtr.AutoSize = true;
            this.label_addtr.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label_addtr.Location = new System.Drawing.Point(11, 9);
            this.label_addtr.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label_addtr.Name = "label_addtr";
            this.label_addtr.Size = new System.Drawing.Size(301, 18);
            this.label_addtr.TabIndex = 16;
            this.label_addtr.Text = "Задать четырехугольник (x,y от -20 до 20)";
            // 
            // textBox_addtr
            // 
            this.textBox_addtr.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBox_addtr.Location = new System.Drawing.Point(11, 31);
            this.textBox_addtr.Margin = new System.Windows.Forms.Padding(2);
            this.textBox_addtr.Name = "textBox_addtr";
            this.textBox_addtr.Size = new System.Drawing.Size(301, 26);
            this.textBox_addtr.TabIndex = 17;
            // 
            // button_addtr
            // 
            this.button_addtr.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.button_addtr.Location = new System.Drawing.Point(11, 72);
            this.button_addtr.Margin = new System.Windows.Forms.Padding(2);
            this.button_addtr.Name = "button_addtr";
            this.button_addtr.Size = new System.Drawing.Size(301, 51);
            this.button_addtr.TabIndex = 18;
            this.button_addtr.Text = "Добавить на рисунок";
            this.button_addtr.UseVisualStyleBackColor = true;
            this.button_addtr.Click += new System.EventHandler(this.button_addtr_Click);
            // 
            // button_check
            // 
            this.button_check.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.button_check.Location = new System.Drawing.Point(11, 140);
            this.button_check.Margin = new System.Windows.Forms.Padding(2);
            this.button_check.Name = "button_check";
            this.button_check.Size = new System.Drawing.Size(301, 64);
            this.button_check.TabIndex = 19;
            this.button_check.Text = "Проверить!";
            this.button_check.UseVisualStyleBackColor = true;
            this.button_check.Click += new System.EventHandler(this.button_check_Click);
            // 
            // textBox1
            // 
            this.textBox1.Enabled = false;
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.textBox1.Location = new System.Drawing.Point(11, 224);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(301, 26);
            this.textBox1.TabIndex = 20;
            this.textBox1.Text = "Нет ошибок.";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(830, 457);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button_check);
            this.Controls.Add(this.button_addtr);
            this.Controls.Add(this.textBox_addtr);
            this.Controls.Add(this.label_addtr);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Проверка на параллелограммность!";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_addtr;
        private System.Windows.Forms.TextBox textBox_addtr;
        private System.Windows.Forms.Button button_addtr;
        private System.Windows.Forms.Button button_check;
        private System.Windows.Forms.TextBox textBox1;
    }
}

