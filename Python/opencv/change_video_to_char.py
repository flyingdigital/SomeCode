'''
1.需要安装的库为opencv-python(pip install opencv-python)
2.请在命令行模式下运行
    Windows环境：
        a.启用了虚拟环境
            cd /your project/env/Script
            activate
            python change_video_to_char.py
        b.未启用虚拟环境
            cd /your project
            python change_video_to_char.py
    Linux环境
        a.启用了虚拟环境
            cd /your project
            source ./env/bin/activate
            python change_video_to_char.py
        b.未启用命令行
            cd /your project
            python change_video_to_char.py

'''

import cv2
import time

show_heigth = 60
show_width = 180

ascii_char = list("$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ")

# 生成一个ascii字符列表
char_len = len(ascii_char)

vc = cv2.VideoCapture("0.mp4")  # 加载一个视频

# 判断是否正常打开
if vc.isOpened():
    rval, frame = vc.read()
else:
    rval = False

outputList = []  # 初始化输出列表
while rval:  # 循环读取视频帧
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  # 使用opencv转化成灰度图
    gray = cv2.resize(gray, (show_width, show_heigth))  # resize灰度图
    text = ""
    for pixel_line in gray:
        for pixel in pixel_line:  # 字符串拼接
            text += ascii_char[int(pixel / 256 * char_len)]
        text += "\n"
    outputList.append(text)
    rval, frame = vc.read()
print("处理完毕")

for frame in outputList:
    print(frame)
    time.sleep(0.02)