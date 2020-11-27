using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml 的互動邏輯
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            this.WindowState = WindowState.Maximized;

            /*FileBar.Width = RootWindow.Width;
            FileBar.Height = RootWindow.Height / 8;
            MainBlock.Width = RootWindow.Width;
            MainBlock.Height = RootWindow.Height - MenuBar.Height - FileBar.Height;
            ToolBar.Width = RootWindow.Width;
            ToolBar.Height = MainBlock.Height;*/
        }

        private void Expander_Expanded(object sender, RoutedEventArgs e)
        {
            
        }

        private void MinimizeButton_Click(object sender, RoutedEventArgs e)
        {
            this.WindowState = WindowState.Minimized;
        }

        private void CloseButton_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void Open_Folder_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Save_to_RAW_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Output_Bitmap_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void Undo_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Redo_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Reset_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Apply_preset_to_this_file_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Apply_preset_to_all_files_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Save_preset_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Traditional_Chinese_Checked(object sender, RoutedEventArgs e)
        {
            English.IsChecked = false;
        }

        private void English_Checked(object sender, RoutedEventArgs e)
        {
            Traditional_Chinese.IsChecked = false;
        }

        private void Upload_customized_language_pack_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Version_Info_Click(object sender, RoutedEventArgs e)
        {

        }
        private void slider0_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox0.Text = slider0.Value.ToString();
        }
        private void slider0_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider0.Value += 1;
            else if (e.Delta < 0)
                slider0.Value -= 1;
        }
        private void slider1_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox1.Text = slider1.Value.ToString();
        }
        private void slider1_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider1.Value += 1;
            else if (e.Delta < 0)
                slider1.Value -= 1;
        }

        private void slider2_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox2.Text = slider2.Value.ToString();
        }
        private void slider2_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider2.Value += 1;
            else if (e.Delta < 0)
                slider2.Value -= 1;
        }
        private void slider3_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox3.Text = slider3.Value.ToString();
        }
        private void slider3_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider3.Value += 1;
            else if (e.Delta < 0)
                slider3.Value -= 1;
        }
        private void slider4_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox4.Text = slider4.Value.ToString();
        }
        private void slider4_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider4.Value += 1;
            else if (e.Delta < 0)
                slider4.Value -= 1;
        }
        private void slider5_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox5.Text = slider5.Value.ToString();
        }
        private void slider5_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider5.Value += 1;
            else if (e.Delta < 0)
                slider5.Value -= 1;
        }
        private void slider6_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox6.Text = slider6.Value.ToString();
        }
        private void slider6_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider6.Value += 1;
            else if (e.Delta < 0)
                slider6.Value -= 1;
        }
        private void slider7_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            textBox7.Text = slider7.Value.ToString();
        }
        private void slider7_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                slider7.Value += 1;
            else if (e.Delta < 0)
                slider7.Value -= 1;
        }
    }
}
