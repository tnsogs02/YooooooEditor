using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Runtime.InteropServices;
using System.Drawing.Imaging;


namespace TestCsharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.Text = "2.png";
        }

        [DllImport("dll1.dll", EntryPoint = "ret", CallingConvention = CallingConvention.Cdecl)]
        static extern int ret(IntPtr imageBuffer, int width, int height, int a, int b, int c, int d, int e, int f, int g, int h, int i);

        Bitmap pimg;

        private void button1_Click(object sender, EventArgs e)
        {
            pimg = new Bitmap(textBox1.Text);
            pictureBox1.Image = pimg;
        }

        void callDII()
        {
            label1.Text = trackBar1.Value.ToString();
            label2.Text = trackBar2.Value.ToString();
            label3.Text = trackBar3.Value.ToString();
            label4.Text = trackBar4.Value.ToString();
            label5.Text = trackBar5.Value.ToString();
            label6.Text = trackBar6.Value.ToString();
            label7.Text = trackBar7.Value.ToString();
            label8.Text = trackBar8.Value.ToString();
            label9.Text = trackBar9.Value.ToString();

            Bitmap img = (Bitmap)pimg.Clone();

            BitmapData bmpData = img.LockBits(new Rectangle(0, 0, img.Width, img.Height), System.Drawing.Imaging.ImageLockMode.ReadWrite,
            System.Drawing.Imaging.PixelFormat.Format24bppRgb);

            int ca = ret(bmpData.Scan0, img.Width, img.Height
                , trackBar1.Value
                , trackBar2.Value
                , trackBar3.Value
                , trackBar4.Value
                , trackBar5.Value
                , trackBar6.Value
                , trackBar7.Value
                , trackBar8.Value
                , trackBar9.Value);

            img.UnlockBits(bmpData); //Remember to unlock!!!

            pictureBox1.Image = img;
            //img.Dispose();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar6_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar7_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar8_Scroll(object sender, EventArgs e)
        {
            callDII();
        }

        private void trackBar9_Scroll(object sender, EventArgs e)
        {
            callDII();
        }
    }
}
