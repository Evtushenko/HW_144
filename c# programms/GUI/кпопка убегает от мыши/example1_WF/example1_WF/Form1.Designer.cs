namespace example1_WF
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
            this.button_yes = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.button_no = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button_yes
            // 
            this.button_yes.Location = new System.Drawing.Point(67, 92);
            this.button_yes.Name = "button_yes";
            this.button_yes.Size = new System.Drawing.Size(75, 23);
            this.button_yes.TabIndex = 0;
            this.button_yes.Text = "да :)";
            this.button_yes.UseVisualStyleBackColor = true;
            this.button_yes.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(32, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(272, 32);
            this.label1.TabIndex = 1;
            this.label1.Text = "Вы довольны собой?";
            // 
            // button_no
            // 
            this.button_no.Location = new System.Drawing.Point(195, 92);
            this.button_no.Name = "button_no";
            this.button_no.Size = new System.Drawing.Size(75, 23);
            this.button_no.TabIndex = 2;
            this.button_no.Text = "нет :(";
            this.button_no.UseVisualStyleBackColor = true;
            this.button_no.MouseMove += new System.Windows.Forms.MouseEventHandler(this.button2_MouseMove);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(322, 125);
            this.Controls.Add(this.button_no);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button_yes);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "Form1";
            this.Text = "Опрос";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button_yes;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_no;
    }
}

