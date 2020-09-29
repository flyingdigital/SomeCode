import pyautogui
import time


# time.sleep(3)

# (120,520)

# # 鼠标现在位置
# old_position = pyautogui.position()
# new_position = old_position
#
# # 获取鼠标当前位置，获取之后需要记下当前坐标（并注释）
# while True:
#     new_position = pyautogui.position()
#     if old_position != new_position:
#         old_position = new_position
#         print(new_position)

# 轰炸

while True:
    pyautogui.click(120, 520)
    time.sleep(6)
