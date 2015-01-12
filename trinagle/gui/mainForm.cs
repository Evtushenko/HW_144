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
using Library_task;

namespace WindowsFormsApplication5
{
    public partial class mainForm : Form
    {

        PaintEventArgs pointer;

        public mainForm()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // Выбрать цвет
            //MessageBox.Show(get_color_from_user());

            // блок добавить точку

            label_add_points.Text = "Добавить точку (0 <= x,y <= 50)";
            label_addp_x.Text = "x:";
            label_addp_y.Text = "y:";
            button_addp.Text = "ADD";

            // блок добавить треугольник
            label_addtr.Text = "Добавить Треугольник в формате x,y;x,y;x,y";
            button_addtr.Text = "ADD";
            textBox_addtr.Text = "0,0;0,3;5,5";
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            // первая цифра отступ слева, вторая сверху, далее длина ширина
            e.Graphics.FillRectangle(Brushes.White, 500, 0, 500, 500);
        }

        private void button_addp_Click(object sender, EventArgs e)
        {
            int x = Convert.ToInt32(textBox_addp_x.Text);
            int y = Convert.ToInt32(textBox_addp_y.Text);

            if (x >= 0 && x <= 50 && y  <= 50 && y >= 0)
            {
                Graphics g = Graphics.FromHwnd(this.Handle);
                g.FillRectangle(Brushes.Blue, 500 + x*10, 500 - y*10 -10, 10, 10);
            }
            else
            {
                MessageBox.Show("только первая четверть и до 50 по модулю!");
            }
        }

        private void button_addtr_Click(object sender, EventArgs e)
        {
            List<Point> points = new List<Point>();
            string query = textBox_addtr.Text;
            foreach (string xy in query.Split(';'))
            {
                int x = Convert.ToInt32(xy.Split(',')[0]);
                int y = Convert.ToInt32(xy.Split(',')[1]);
                Graphics g = Graphics.FromHwnd(this.Handle);
                g.FillRectangle(Brushes.Red, 500 + x * 10, 500 - y * 10 - 10, 10, 10);
                points.Add(new Point(500 + x * 10 + 5, 500 - y * 10 - 5));
            }
            Point[] polygonPoints = points.ToArray();
            Graphics gmc = Graphics.FromHwnd(this.Handle);
            gmc.FillPolygon(Brushes.Tan, polygonPoints);
            gmc.DrawPolygon(Pens.DarkGoldenrod, polygonPoints);
        }

        private void button_belong_Click(object sender, EventArgs e)
        {
            List<MyPoint> points = new List<MyPoint>();
            string query = textBox_addtr.Text;
            foreach (string xy in query.Split(';'))
            {
                int x = Convert.ToInt32(xy.Split(',')[0]);
                int y = Convert.ToInt32(xy.Split(',')[1]);
                points.Add(new MyPoint(x, y));
            }
            MyTriangle triangle = new MyTriangle(points[0], points[1], points[2]);

            int point_x = Convert.ToInt32(textBox_addp_x.Text);
            int point_y = Convert.ToInt32(textBox_addp_y.Text);
            MyPoint suspect = new MyPoint(point_x, point_y);
            if (triangle.MyPointBelong(suspect))
            {
                MessageBox.Show("Belongs!!!");
            }
            else
            {
                MessageBox.Show("Not Belongs!!!");
            }
        }
    }
}
