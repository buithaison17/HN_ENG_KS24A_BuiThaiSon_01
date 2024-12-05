#include<stdio.h>
int main(){
	int arr[100], length, n, choice;
	do{
		printf("\nMENU\n");
		printf("1. Nhap so phan tu va gia tri cua tung phan tu\n");
		printf("2. In ra tung phan tu trong mang\n");
		printf("3. In gia tri nho nhat va lon nhat\n");
		printf("4. In tong cac phan tu\n");
		printf("5. Them mot phan tu vao cuoi mang\n");
		printf("6. Xoa mot phan tu\n");
		printf("7. Sap xep mang theo thu tu giam dan (bubble sort)\n");
		printf("8. Tim kiem phan tu (liner search)\n");
		printf("9. In ra so nguyen to\n");
		printf("10. Sap xep theo thu tu tang dan (selection sort)\n");
		printf("11. Thoat\n");
		printf("Hay chon chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nNhap so phan tu cua mang (toi da 100): ");
				scanf("%d", &length);
				if(length < 1 || length > 100){
					printf("\nNhap khong hop le\n");
					n = 0;
				}
				else{
					n = length;
					for(int i = 0; i < length; i++){
						printf("\nNhap phan tu arr[%d]: ", i);
						scanf("%d", &arr[i]);
					}
				}
				break;
			case 2:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					for(int i = 0; i < n; i++){
						printf("\narr[%d] = %d", i, arr[i]);
					}
					printf("\n");
				}
				break;
			case 3:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					int min = arr[0], max = arr[0];
					for(int i = 1; i < n; i++){
						if(max < arr[i]){
							max = arr[i];
						}
						if(min > arr[i]){
							min = arr[i];
						}
					}
					printf("\nPhan tu lon nhat trong mang la: %d\n", max);
					printf("\nPhan tu nho nhat trong mang la: %d\n", min);
				}
				break;
			case 4:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					int sum = 0;
					for(int i = 0; i < n; i++){
						sum += arr[i];
					}
					printf("\nTong cac phan tu trong mang la: %d\n", sum);
				}
				break;
			case 5:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else if(n >= length){
					printf("\nMang da day khong the them phan tu\n");
				}
				else{
					for(int i = n; i < n - 1; i--){
						arr[i] = arr[i-1];
					}
					n++;
					printf("\nNhap phan tu muon them: ");
					scanf("%d", &arr[n-1]);
					printf("\nThem hoan tat\n");
				}
				break;
			case 6:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					int index;
					printf("\nNhap vi tri muon xoa (0 --> %d): ", n-1);
					scanf("%d", &index);
					if(index < 0 || index > n-1){
						printf("\nVi tri xoa khong hop le\n");
					}
					else{
						for(int i = index; i < n; i++){
							arr[i] = arr[i+1];
						}
						n--;
						printf("\nXoa hoan tat\n");
					}
				}
				break;
			case 7:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					for(int i = 0; i < n; i++){
						for(int j = 0; j < n - i -1; j++){
							if(arr[j] < arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}
						}
					}
					printf("\nSap xep hoan tat bam 2 de in ra\n");
				}
				break;
			case 8:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					int numbers, index = 0, arrIndex[100];
					printf("\nNhap phan tu muon tim kiem: ");
					scanf("%d", &numbers);
					for(int i = 0; i < n; i++){
						if(numbers == arr[i]){
							arrIndex[index] = i;
							index++;
						}
					}
					if(index == 0){
						printf("\nPhan tu khong ton tai\n");
					}
					else{
						printf("\nPhan tu %d co vi tri la: ", numbers);
						for(int i = 0; i < index; i++){
							printf("arr[%d] ", arrIndex[i]);
						}
						printf("\n");
					}
				}
				break;
			case 9:
				if(n == 0){
					printf("\nChua them gia tri vao mang\n");
				}
				else{
					int soNguyenTo[100], index = 0;
					for(int i = 0; i < n; i++){
						int count = 0;
						for(int j = 1; j <= arr[i]; j++){
							if(arr[i] % j == 0){
								count++;
							}
						}
						if(count == 2){
							soNguyenTo[index] = arr[i];
							index++;
						}
					}
					if(index == 0){
						printf("\nMang da nhap khong co so nguyen to\n");
					}
					else{
						printf("\nSo nguyen to trong mang la: ");
						for(int i = 0; i < index; i++){
							printf("%d ", soNguyenTo[i]);
						}
						printf("\n");
					}
				}
				break;
			case 10:
				if(n == 0){
					printf("\nChua them phan tu vao mang\n");
				}
				else{
					int minIndex;
					for(int i = 0; i < n; i++){
						minIndex = i;
						for(int j = i + 1; j < n; j++){
							if(arr[minIndex] > arr[j]){
								minIndex = j;
							}
						}
						if(minIndex != i){
							int temp = arr[i];
							arr[i]= arr[minIndex];
							arr[minIndex] = temp;
						}
					}
					printf("\nSap xep hoan tat bam 2 de in ra\n");
				}
				break;
			case 11:
				printf("\nThoat hoan tat\n");
				break;
			default:
				printf("\nKhong co chuc nang nay hay nhap lai\n");
				break;
		}
	}
	while(choice != 11);
	return 0;
}
