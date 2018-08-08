import os
import urllib
import urllib.request

def save_img(img_url,file_name,file_path='book\img'):
    #目标文件
    save_path=r'D:\picturenote' #保存路径

    if not os.path.exists(save_path):
        os.makedirs(save_path)

    urllib.request.urlretrieve(img_url,save_path+fileName)

for i in range(10000000,20000000):
    save_img('https://idb.bjtu.edu.cn/admin/people/photo/'+str(i)+'.jpg',str(i)+".jpg")
