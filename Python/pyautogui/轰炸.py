import pyautogui
import time

time.sleep(3)

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
pyautogui.click(x=950, y=730)
while True:
    pyautogui.hotkey('ctrl', 'v')
    pyautogui.hotkey('enter')

    # 有时间间隔避免被封
    time.sleep(0.4)
