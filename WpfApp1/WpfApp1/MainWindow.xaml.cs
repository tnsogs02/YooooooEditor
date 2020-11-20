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

        private void slider1_DragEnter(object sender, DragEventArgs e)
        {

        }

        private void slider1_DragLeave(object sender, DragEventArgs e)
        {

        }

        private void slider0_DragEnter(object sender, DragEventArgs e)
        {

        }

        private void slider0_DragLeave(object sender, DragEventArgs e)
        {

        }

        private void slider0_MouseWheel(object sender, MouseWheelEventArgs e)
        {
        }
    }
}
