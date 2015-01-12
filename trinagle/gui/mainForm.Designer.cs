namespace WindowsFormsApplication5
{
    partial class mainForm
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
            this.label_add_points = new System.Windows.Forms.Label();
            this.label_addp_x = new System.Windows.Forms.Label();
            this.label_addp_y = new System.Windows.Forms.Label();
            this.textBox_addp_y = new System.Windows.Forms.TextBox();
            this.textBox_addp_x = new System.Windows.Forms.TextBox();
            this.button_addp = new System.Windows.Forms.Button();
            this.label_addtr = new System.Windows.Forms.Label();
            this.textBox_addtr = new System.Windows.Forms.TextBox();
            this.button_addtr = new System.Windows.Forms.Button();
            this.button_belong = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label_add_points
            // 
            this.label_add_points.AutoSize = true;
            this.label_add_points.Location = new System.Drawing.Point(232, 215);
            this.label_add_points.Name = "label_add_points";
            this.label_add_points.Size = new System.Drawing.Size(116, 17);
            this.label_add_points.TabIndex = 9;
            this.label_add_points.Text = "label_add_points";
            // 
            // label_addp_x
            // 
            this.label_addp_x.AutoSize = true;
            this.label_addp_x.Location = new System.Drawing.Point(175, 291);
            this.label_addp_x.Name = "label_addp_x";
            this.label_addp_x.Size = new System.Drawing.Size(46, 17);
            this.label_addp_x.TabIndex = 11;
            this.label_addp_x.Text = "label1";
            // 
            // label_addp_y
            // 
            this.label_addp_y.AutoSize = true;
            this.label_addp_y.Location = new System.Drawing.Point(175, 244);
            this.label_addp_y.Name = "label_addp_y";
            this.label_addp_y.Size = new System.Drawing.Size(46, 17);
            this.label_addp_y.TabIndex = 12;
            this.label_addp_y.Text = "label2";
            // 
            // textBox_addp_y
            // 
            this.textBox_addp_y.Location = new System.Drawing.Point(235, 244);
            this.textBox_addp_y.Name = "textBox_addp_y";
            this.textBox_addp_y.Size = new System.Drawing.Size(100, 22);
            this.textBox_addp_y.TabIndex = 13;
            // 
            // textBox_addp_x
            // 
            this.textBox_addp_x.Location = new System.Drawing.Point(235, 291);
            this.textBox_addp_x.Name = "textBox_addp_x";
            this.textBox_addp_x.Size = new System.Drawing.Size(100, 22);
            this.textBox_addp_x.TabIndex = 14;
            // 
            // button_addp
            // 
            this.button_addp.Location = new System.Drawing.Point(358, 244);
            this.button_addp.Name = "button_addp";
            this.button_addp.Size = new System.Drawing.Size(92, 69);
            this.button_addp.TabIndex = 15;
            this.button_addp.Text = "button1";
            this.button_addp.UseVisualStyleBackColor = true;
            this.button_addp.Click += new System.EventHandler(this.button_addp_Click);
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
            this.textBox_addtr.Size = new System.Drawing.Size(100, 22);
            this.textBox_addtr.TabIndex = 17;
            // 
            // button_addtr
            // 
            this.button_addtr.Location = new System.Drawing.Point(261, 357);
            this.button_addtr.Name = "button_addtr";
            this.button_addtr.Size = new System.Drawing.Size(87, 63);
            this.button_addtr.TabIndex = 18;
            this.button_addtr.Text = "button1";
            this.button_addtr.UseVisualStyleBackColor = true;
            this.button_addtr.Click += new System.EventHandler(this.button_addtr_Click);
            // 
            // button_belong
            // 
            this.button_belong.Location = new System.Drawing.Point(456, 244);
            this.button_belong.Name = "button_belong";
            this.button_belong.Size = new System.Drawing.Size(92, 69);
            this.button_belong.TabIndex = 19;
            this.button_belong.Text = "button_belongs";
            this.button_belong.UseVisualStyleBackColor = true;
            this.button_belong.Click += new System.EventHandler(this.button_belong_Click);
            // 
            // mainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1682, 753);
            this.Controls.Add(this.button_belong);
            this.Controls.Add(this.button_addtr);
            this.Controls.Add(this.textBox_addtr);
            this.Controls.Add(this.label_addtr);
            this.Controls.Add(this.button_addp);
            this.Controls.Add(this.textBox_addp_x);
            this.Controls.Add(this.textBox_addp_y);
            this.Controls.Add(this.label_addp_y);
            this.Controls.Add(this.label_addp_x);
            this.Controls.Add(this.label_add_points);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "mainForm";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_add_points;
        private System.Windows.Forms.Label label_addp_x;
        private System.Windows.Forms.Label label_addp_y;
        private System.Windows.Forms.TextBox textBox_addp_y;
        private System.Windows.Forms.TextBox textBox_addp_x;
        private System.Windows.Forms.Button button_addp;
        private System.Windows.Forms.Label label_addtr;
        private System.Windows.Forms.TextBox textBox_addtr;
        private System.Windows.Forms.Button button_addtr;
        private System.Windows.Forms.Button button_belong;
    }
}

