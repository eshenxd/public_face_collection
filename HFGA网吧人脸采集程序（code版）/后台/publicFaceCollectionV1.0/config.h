#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

struct Config
{
	int up_hour, up_minute, up_second;
	int delete_hour, delete_minute, delete_second;
	int FD_iterations;
	int show_width, show_height;
	int Align_iterations;
	int pic_width, pic_height;
	float window_scale;

	bool begin_flag;  /** <true表示开始采集图像，false表示不采集，这是由读卡器传输过来的信息*/
	int begin_photo_count;/** <存放当前目录下身份证文件的数目*/

	bool time_flag_up;
	bool time_flag_delete;

	std::string card_photo_path;
	std::string copy_path;

	bool inti_config();
	bool up_time_same();
	bool delete_time_same();

	int year, month, day, hour, minute, second;
private:
	
	
	bool read_configFiles();
};





#endif