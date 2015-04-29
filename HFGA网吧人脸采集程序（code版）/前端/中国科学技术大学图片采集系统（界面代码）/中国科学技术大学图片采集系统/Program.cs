using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace 中国科学技术大学图片采集系统
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
