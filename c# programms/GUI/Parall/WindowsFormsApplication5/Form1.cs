using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using ConsoleApplication1;

namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
        PaintEventArgs pointer;

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // блок добавить четырехугольник
            //label_addtr.Text = "Добавить Четырехугольник в формате x,y;x,y;x,y;x,y где x,y от 0 до 50";
            textBox_addtr.Text = "0,0;0,10;10,10;10,0";
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            e.Graphics.FillRectangle(Brushes.White, 350, 0, 500, 500);
        }

        private void button_addtr_Click(object sender, EventArgs e)
        {
            List<Point> points = new List<Point>();
            int exeption = 0;
            string query = textBox_addtr.Text;
            foreach (string xy in query.Split(';'))
            {
                int x = Convert.ToInt32(xy.Split(',')[0]);
                int y = Convert.ToInt32(xy.Split(',')[1]);
                if ((x < -20) | (x > 20) | (y < -20) | (y > 20))
                {
                    exeption = 1;
                }
                Graphics g = Graphics.FromHwnd(this.Handle);
                g.FillRectangle(Brushes.White, 350, 0, 500, 500);
                points.Add(new Point(600 + x * 10, 225 - y * 10));
            }
            if (exeption != 1) {
                textBox1.Text = "Нет ошибок.";
                Point[] polygonPoints = points.ToArray();
                Graphics gmc = Graphics.FromHwnd(this.Handle);
                gmc.FillPolygon(Brushes.Tan, polygonPoints);
                gmc.DrawPolygon(Pens.Red, polygonPoints);
            }
            else
            {
                textBox1.Text = "Ошибка при вводе координат.";
            }
        }

        private void button_check_Click(object sender, EventArgs e)
        {
            List<MyPoint> points = new List<MyPoint>();
            string query = textBox_addtr.Text;
            foreach (string xy in query.Split(';'))
            {
                int x = Convert.ToInt32(xy.Split(',')[0]);
                int y = Convert.ToInt32(xy.Split(',')[1]);
                points.Add(new MyPoint(x, y));
            }
            myParallelogram par = new myParallelogram(points[0], points[1], points[2], points[3]);
            if (par.isCorrect())
            {
                MessageBox.Show("Параллелограмм");
            }
            else
            {
                MessageBox.Show("Не является параллелограммом");
            }
        }
    }
}
