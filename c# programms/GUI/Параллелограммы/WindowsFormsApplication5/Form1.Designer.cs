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
            this.SuspendLayout();
            // 
            // label_addtr
            // 
            this.label_addtr.AutoSize = true;
            this.label_addtr.Location = new System.Drawing.Point(148, 336);
            this.label_addtr.Name = "label_addtr";
            this.label_addtr.Size = new System.Drawing.Size(46, 17);
            this.label_addtr.TabIndex = 16;
            this.label_addtr.Text = "label1";
            // 
            // textBox_addtr
            // 
            this.textBox_addtr.Location = new System.Drawing.Point(151, 357);
            this.textBox_addtr.Name = "textBox_addtr";
            this.textBox_addtr.Size = new System.Drawing.Size(159, 22);
            this.textBox_addtr.TabIndex = 17;
            // 
            // button_addtr
            // 
            this.button_addtr.Location = new System.Drawing.Point(328, 357);
            this.button_addtr.Name = "button_addtr";
            this.button_addtr.Size = new System.Drawing.Size(87, 63);
            this.button_addtr.TabIndex = 18;
            this.button_addtr.Text = "button1";
            this.button_addtr.UseVisualStyleBackColor = true;
            this.button_addtr.Click += new System.EventHandler(this.button_addtr_Click);
            // 
            // button_check
            // 
            this.button_check.Location = new System.Drawing.Point(421, 357);
            this.button_check.Name = "button_check";
            this.button_check.Size = new System.Drawing.Size(132, 79);
            this.button_check.TabIndex = 19;
            this.button_check.Text = "button1";
            this.button_check.UseVisualStyleBackColor = true;
            this.button_check.Click += new System.EventHandler(this.button_check_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1301, 522);
            this.Controls.Add(this.button_check);
            this.Controls.Add(this.button_addtr);
            this.Controls.Add(this.textBox_addtr);
            this.Controls.Add(this.label_addtr);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_addtr;
        private System.Windows.Forms.TextBox textBox_addtr;
        private System.Windows.Forms.Button button_addtr;
        private System.Windows.Forms.Button button_check;
    }
}

