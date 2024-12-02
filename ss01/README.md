# Bài 1:

|--------------------|-------------------------------------------------------------------|
| Hình dạng | Ý nghĩa |
|--------------------|-------------------------------------------------------------------|
| Oval (Hình elip) | Bắt đầu hoặc kết thúc của một quy trình |
|--------------------|-------------------------------------------------------------------|
| Hình chữ nhật | Một bước thực hiện hoặc hành động trong quy trình |
|--------------------|-------------------------------------------------------------------|
| Hình thoi | Điểm quyết định hoặc điều kiện yêu cầu lựa chọn (ví dụ: Có/Không) |
|--------------------|-------------------------------------------------------------------|
| Mũ tên | Chỉ hướng hoặc luồng của quy trình từ bước này đến bước khác |
|--------------------|-------------------------------------------------------------------|

# Bài 2:

|-----------------------|----------------------------------------------|-----------------------------------------|
| Loại cấu trúc dữ liệu | Đặc điểm chính | Ứng dụng phổ biến |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Mảng (Array) | Lưu trữ các phần tử dữ liệu trong một Khối | Lưu trữ dữ liệu, tìm kiếm, thuật toán |
| | bộ nhớ liên tục, dễ dàng truy cập phần | sắp xếp |
| | tử dựa trên chỉ mục | |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Danh sách liên kết | Một chuỗi các phần tử được liên kết với nhau | Triển khai ngăn xếp, hàng đợi hoặc các |
| (LinkedList) | thông qua con trỏ | cấu trúc động |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Ngăn xếp | Cấu trúc truy cập theo nguyên tắc "LIFO" | Duyệt biểu thức, gọi hàm đệ quy, kiểm |
| | (Last In, First Out). Phần tử vào sau sẽ được| tra dấu ngoặc |
| | lấy ra đầu tiên | |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Hàng đợi | Cấu trúc truy cập theo nguyên tắc "FIFO" | Quản lý luồng dữ liệu, lập lịch CPU, |
| | (First In, First Out). Phần tử vào trước sẽ | hàng đợi in |
| | được lấy ra đầu tiên | |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Cây | Cấu trúc phân cấp với một phần tử gốc và các | Tìm kiếm nhanh, tổ chức dữ liệu, Biểu |
| | phần tử con | diễn các mối quan hệ phân cấp |
|-----------------------|----------------------------------------------|-----------------------------------------|
| Đồ thị | Cấu trúc bao gồm các nút (đỉnh) và các cạnh | Mạng máy tính, định tuyến, biểu đồ xã |
| | kết nối các nút với nhau | hội, tìm đường đi |
|-----------------------|----------------------------------------------------------------------------------------|

# bài 3:

## Lưu trữ danh sách sinh viên theo thứ tự nhập vào:

- Cấu trúc dữ liệu: Danh sách liên kết hoặc mảng.
- Lý do:

* Danh sách liên kết: Thích hợp khi cần chèn/xóa sinh viên một cách linh hoạt tại bất kỳ vị trí nào mà không phải dịch chuyển phần tử.
* Mảng: Dễ truy cập ngẫu nhiên theo chỉ mục và hiệu quả khi danh sách không thay đổi nhiều.

## Tìm kiếm nhanh tên một sản phẩm trong danh sách hàng triệu sản phẩm:

- Cấu trúc dữ liệu: Hash table.
- lý do: Tìm kiếm nhanh với thời gian trung bình nếu sử dụng hàm băm hiệu quả.

## Lưu trữ dữ liệu hệ thống phân cấp như thư mục máy tính:

- Cấu trúc dữ liệu: Cây (tree).
- Lý do: Dữ liệu phân cấp tự nhiên phù hợp với cấu trúc cây. Mỗi thư mục hoặc file là một node, và thư mục cha liên kết với các thư mục con, hỗ trợ thao tác duyệt, thêm hoặc xóa nhanh chóng.

## Tìm đường đi ngắn nhất giữa 2 điểm trên bản đồ:

- Cấu trúc dữ liệu: Đồ thị (Graph).
- Lý do: Đại diện các điểm (đỉnh) và đường nối (cạnh) giữa các điểm, với trọng số là độ dài đường đi. Các thuật toán như Dijkstra hoặc A\* được sử dụng trên đồ thị để tìm đường ngắn nhất.
