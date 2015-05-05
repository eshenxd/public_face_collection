using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace 中国科学技术大学图片采集系统
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        System.Diagnostics.Process process = new System.Diagnostics.Process();

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            string file_hour="../config/up_hour.ini";
            FileStream hour_set_file = new FileStream(file_hour, FileMode.Create);
            StreamWriter hour_write = new StreamWriter(hour_set_file);
            hour_write.Write(textBox3.Text);
            hour_write.Write('\n');
            hour_write.Close();
            hour_set_file.Close();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            string file_min = "../config/up_minute.ini";
            FileStream min_set_file = new FileStream(file_min, FileMode.Create);
            StreamWriter min_write = new StreamWriter(min_set_file);
            min_write.Write(textBox2.Text);
            min_write.Write('\n');
            min_write.Close();
            min_set_file.Close();
        }

       

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            string file_send1 = "begin_send1.ini";
            FileStream send1_set_file = new FileStream(file_send1, FileMode.Create);
            StreamWriter send1_write = new StreamWriter(send1_set_file);
            send1_write.Write(textBox5.Text);
            send1_write.Write('\n');
            send1_write.Close();
            send1_set_file.Close();
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            string file_send2 = "begin_send2.ini";
            FileStream send2_set_file = new FileStream(file_send2, FileMode.Create);
            StreamWriter send2_write = new StreamWriter(send2_set_file);
            send2_write.Write(textBox6.Text);
            send2_write.Write('\n');
            send2_write.Close();
            send2_set_file.Close();
        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {
            string file_path1 = "../config/setfile_1.ini";
            FileStream path1_set_file = new FileStream(file_path1, FileMode.Create);
            StreamWriter path1_write = new StreamWriter(path1_set_file);
            path1_write.Write(textBox8.Text+"\\");
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();
        }

       

        private void textBox9_TextChanged(object sender, EventArgs e)
        {
            string file_width = "../config/show_width.ini";
            FileStream width_set_file = new FileStream(file_width, FileMode.Create);
            StreamWriter width_write = new StreamWriter(width_set_file);
            width_write.Write(textBox9.Text);
            width_write.Write('\n');
            width_write.Close();
            width_set_file.Close();
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {
            string file_height = "../config/show_height.ini";
            FileStream height_set_file = new FileStream(file_height, FileMode.Create);
            StreamWriter height_write = new StreamWriter(height_set_file);
            height_write.Write(textBox10.Text);
            height_write.Write('\n');
            height_write.Close();
            height_set_file.Close();
        }

        private void textBox12_TextChanged(object sender, EventArgs e)
        {
            string file_scale1 = "../config/Windows_scale.ini";
            FileStream scale1_set_file = new FileStream(file_scale1, FileMode.Create);
            StreamWriter scale1_write = new StreamWriter(scale1_set_file);
            scale1_write.Write(textBox12.Text);
            scale1_write.Write('\n');
            scale1_write.Close();
            scale1_set_file.Close();
        }

        

        private void button3_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();

            if (fbd.ShowDialog() == DialogResult.OK)
            {
                this.textBox8.Text = fbd.SelectedPath;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();

            if (fbd.ShowDialog() == DialogResult.OK)
            {
                this.textBox7.Text = fbd.SelectedPath;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (process.StartInfo.FileName == "publicFaceCollectionV1.0.exe")
            {
                MessageBox.Show("程序已启动！");
            }
            else
            {
                string exe_path = "publicFaceCollectionV1.0.exe";
                //System.Diagnostics.Process process = new System.Diagnostics.Process();
                process.StartInfo.FileName = "publicFaceCollectionV1.0.exe";
                process.StartInfo.WorkingDirectory = exe_path;
                process.StartInfo.CreateNoWindow = true;
                process.Start();
            }
            
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {
        
        }

        private void textBox4_TextChanged_1(object sender, EventArgs e)
        {
            string file_delete = "../config/delete_hour.ini";
            FileStream delete_set_file = new FileStream(file_delete, FileMode.Create);
            StreamWriter delete_write = new StreamWriter(delete_set_file);
            delete_write.Write(textBox4.Text);
            delete_write.Write('\n');
            delete_write.Close();
            delete_write.Close();
        }

        private void textBox5_TextChanged_1(object sender, EventArgs e)
        {
            string file_delete = "../config/delete_minute.ini";
            FileStream delete_set_file = new FileStream(file_delete, FileMode.Create);
            StreamWriter delete_write = new StreamWriter(delete_set_file);
            delete_write.Write(textBox5.Text);
            delete_write.Write('\n');
            delete_write.Close();
            delete_write.Close();
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();

            if (fbd.ShowDialog() == DialogResult.OK)
            {
                this.textBox7.Text = fbd.SelectedPath;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();

            if (fbd.ShowDialog() == DialogResult.OK)
            {
                this.textBox13.Text = fbd.SelectedPath;
            }
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            string cardphotopath = "../config/cardphotopath.ini";
            FileStream path1_set_file = new FileStream(cardphotopath, FileMode.Create);
            StreamWriter path1_write = new StreamWriter(path1_set_file);
            path1_write.Write(textBox7.Text);
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();
        }

        private void textBox13_TextChanged(object sender, EventArgs e)
        {
            string copypath = "../config/copypath.ini";
            FileStream path1_set_file = new FileStream(copypath, FileMode.Create);
            StreamWriter path1_write = new StreamWriter(path1_set_file);
            path1_write.Write(textBox13.Text);
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (process.StartInfo.FileName == "publicFaceCollectionV1.0.exe")
            {
                process.Kill();
                Thread.Sleep(1000);

                process.Start();
            }
                
            else
            {
                MessageBox.Show("请先启动进程！");
                //string exe_path = "publicFaceCollectionV1.0.exe";
                ////System.Diagnostics.Process process = new System.Diagnostics.Process();
                //process.StartInfo.FileName = "publicFaceCollectionV1.0.exe";
                //process.StartInfo.WorkingDirectory = exe_path;
                //process.StartInfo.CreateNoWindow = true;
                //process.Start();
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (process.StartInfo.FileName == "publicFaceCollectionV1.0.exe")
            {
                process.Kill();
            }
            
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //设定采集总数
            string path = "../config/filesum_1.ini";
            FileStream path1_set_file = new FileStream(path, FileMode.Create);
            StreamWriter path1_write = new StreamWriter(path1_set_file);
            path1_write.Write("1");
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();

            //设定开始删除数
            path = "../config/begin_send1.ini";
            path1_set_file = new FileStream(path, FileMode.Create);
            path1_write = new StreamWriter(path1_set_file);
            path1_write.Write("1");
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();
            //设定开始上传数
            path = "../config/begin_delete1.ini";
            path1_set_file = new FileStream(path, FileMode.Create);
            path1_write = new StreamWriter(path1_set_file);
            path1_write.Write("1");
            path1_write.Write('\n');
            path1_write.Close();
            path1_set_file.Close();

            MessageBox.Show("初始化完成！");
        }

       

        private void Form1_DoubleClick(object sender, EventArgs e)
        {
            notifyIcon1.Visible = true;
            this.Hide();
        }

        private void notifyIcon1_MouseDown(object sender, MouseEventArgs e)
        {
            this.Show();
            notifyIcon1.Visible = false;
            this.ShowInTaskbar = true;
        }

       

       
    }
}
