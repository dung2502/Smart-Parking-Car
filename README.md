# Smart-Parking-Car (Bãi Đỗ Xe Thông Minh)

**Bãi Đỗ Xe Thông Minh** là một ứng dụng web quản lý dữ liệu xe ra vào bãi đỗ một cách tự động. Dự án này được xây dựng bằng **React.js** cho phía client và **Django** (Python) cho phía server, tích hợp thêm AI nhận diện biển số xe nhằm tăng cường bảo mật và giảm tải cho việc quản lý.

## Tính năng chính

- Quản lý xe ra vào bãi đỗ tự động.
- Nhận diện biển số xe sử dụng AI (YOLOv8).
- Tích hợp RFID để quét thẻ ra vào bãi đỗ.
- Giao diện người dùng thân thiện và trực quan.

## Công nghệ sử dụng

### Phía Client:
- **React.js**: Thư viện JavaScript để xây dựng giao diện người dùng.

### Phía Server:
- **Django**: Framework Python mạnh mẽ cho phía server, cung cấp API và xử lý logic backend.

### Phía AI:
- **YOLOv8**: Dùng để training mô hình nhận diện vật thể và ký tự trên biển số xe.

### Phần cứng:
- **Arduino**: Sử dụng để vận hành hệ thống với RFID, giúp quét thẻ khi xe ra vào bãi.

## Cài đặt và chạy dự án

### 1. Cài đặt và chạy Client (React.js)

```bash
# Di chuyển vào thư mục client
cd client

# Cài đặt các dependencies
npm install

# Chạy ứng dụng client
npm start
```

Client sẽ chạy tại `http://localhost:3000`.

### 2. Cài đặt và chạy Server (Django)

```bash
# Di chuyển vào thư mục server
cd server

# Cài đặt các dependencies (trong môi trường ảo hoặc global)
pip install -r requirements.txt

# Chạy server
python manage.py runserver
```

Server sẽ chạy tại `http://localhost:5000`.

## Cấu trúc thư mục

```bash
client/    # Mã nguồn cho phía client (React.js)
server/    # Mã nguồn cho phía server (Django)
ai/        # Các file mô hình AI và notebook dùng để training nhận diện biển số xe
```

## AI và nhận diện biển số xe

- **YOLOv8**: Sử dụng để huấn luyện mô hình nhận diện biển số xe và các ký tự trên biển số.
  - `character.ipynb`: Notebook dùng để training mô hình nhận diện ký tự.
  - `PlateNumber.ipynb`: Notebook dùng để training mô hình nhận diện biển số xe.

## Phần cứng

- **Arduino**: Được sử dụng để quản lý các cảm biến và thiết bị điều khiển trong hệ thống. Kết hợp với **RFID** để quét thẻ khi xe ra vào bãi đỗ.

## Yêu cầu hệ thống

### Client:
- Node.js
- NPM

### Server:
- Python 3.x
- Django

### Phần cứng:
- Arduino
- Cảm biến RFID

## Thành viên dự án

- **Nguyễn Đức Dũng** - Phát triển hệ thống.
