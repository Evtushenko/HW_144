using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace example1_WF
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Мы и не сомневались, что Вы так думаете!");
        }

        private void button2_MouseMove(object sender, MouseEventArgs e)
        {
            button_no.Top -= e.Y;
            button_no.Left += e.X;
            if (button_no.Top < -10 || button_no.Top > 100)
                button_no.Top = 60;
            if (button_no.Left < -80 || button_no.Left > 250)
                button_no.Left = 120;
        }
    }
}
