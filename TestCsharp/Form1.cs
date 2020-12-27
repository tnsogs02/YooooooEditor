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
        static extern int ret(IntPtr imageBuffer, int width, int height, int ch);

        Bitmap pimg;

        private void button1_Click(object sender, EventArgs e)
        {
            pimg = new Bitmap(textBox1.Text);
            pictureBox1.Image = pimg;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            label1.Text = trackBar1.Value.ToString();

            Bitmap img = (Bitmap)pimg.Clone();

            BitmapData bmpData = img.LockBits(new Rectangle(0, 0, img.Width, img.Height), System.Drawing.Imaging.ImageLockMode.ReadWrite,
            System.Drawing.Imaging.PixelFormat.Format24bppRgb);

            int ca = ret(bmpData.Scan0, img.Width, img.Height, trackBar1.Value);

            img.UnlockBits(bmpData); //Remember to unlock!!!

            pictureBox1.Image = img;
            //img.Dispose();
        }
    }
}
