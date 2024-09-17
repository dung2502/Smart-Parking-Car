# Smart-Parking-Car

BaiDoXeThongMinh là một ứng dụng web quản lý dữ liệu xe vào-ra bãi đỗ một cách tự động. Dự án này được xây dựng bằng React.js cho phía client và Django (Python) cho phía server. Ứng dụng được tích hợp Ai nhận diện biển số xe nhằm tăng thêm tính bảo mật và giảm bớt gánh nặng trong việc quản lý.

*Phía Server:
## Cài đặt và Chạy

1. Client (React.js)
```bash
# Cài đặt dependencies
npm install
```
2. Server (Django)
```bash
# Cài đặt dependencies (trong môi trường ảo hoặc global)
pip install -r requirements.txt
```
3. Chạy server: python manage.py runserver
Server sẽ chạy tại http://localhost:5000.

## Cấu trúc Thư mục
client/: Mã nguồn cho phía client.
server/: Mã nguồn cho phía server.
## Phụ thuộc
Client
React.js
Server
Django

*Phía AI: Sử dụng model Ai YOLOv8 để trainning nhận diện diện vật thể và ký tự.
1. File character.ipynb dùng để trainning Các ký tự.
2. File PlateNumber.ipynb dùng để trainning nhận diện biển số.

*Phía phần cứng:
1. Sử dụng phần cứng là arduino để vận hành hệ thống có kết hợp rfid để quyệt thẻ khi ra vào có kết hợp 

## Thành viên dự án:
Nguyễn Đức Dũng

