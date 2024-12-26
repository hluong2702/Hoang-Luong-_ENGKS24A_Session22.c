#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Student {
    int id;
    char name[100];
    int age;
    char phoneNumber[100];
};
void showStudent(struct Student student[], int *count);
void addStudent(struct Student student[], int *count,struct Student newStudent);
int idCheck(struct Student student[], int *count,struct Student newStudent);
void updateStudent(struct Student student[], int *count,struct Student newStudent,int choice,int index);
void deleteStudent(struct Student student[], int *count,int index);
void searchStudent(struct Student student[], int *count,int choice,struct Student findStudent);
void sortStudent(struct Student student[], int *count, int choice);
int main(){
    int choice,index;
    char searchName[100];
    char searchPhoneNumber[100];
    struct Student student[5] = 
    {
       {1,"Hoang Van Luong",18,"0367771862"},
        {2,"Hoang Van Luong",19,"0367771862"},
        {3,"Hoang Van Luong",20,"00367771862"},
        {4,"Hoang Van Luong",21,"0367771862"},
        {5,"Hoang Van Luong",21,"0367771862"},
    }; 
    struct Student newStudent;
    struct Student findStudent;
    int count = 5;
    do
    {
        printf("__________________________________________________\n");
        printf("                        Menu\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban : ");
        scanf("%d",&choice);
        printf("__________________________________________________\n");
        switch (choice)
        {
        case 1:
            showStudent(student,&count);
            break;
        case 2:
            do
            {
                printf("Nhap ID : ");
                scanf("%d",&newStudent.id);
            } while (idCheck(student,&count,newStudent));
            printf("Nhap ten : ");
            fflush(stdin);
            fgets(newStudent.name,sizeof(newStudent.name),stdin);
            newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
            printf("Nhap tuoi : ");
            scanf("%d",&newStudent.age);
            printf("Nhap so dien thoai : ");
            fflush(stdin);
            fgets(newStudent.phoneNumber,sizeof(newStudent.phoneNumber),stdin);
            newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';
            addStudent(student,&count,newStudent);
            showStudent(student,&count);
            break;
        case 3:
            printf("Nhap vi tri cua sinh vien ban muon sua thong tin : ");
            scanf("%d",&index);
            printf("Ban muon sua thong tin nao :\n");
            printf("1, ID sinh vien\n");
            printf("2, Ten sinh vien\n");
            printf("3, Tuoi sinh vien\n");
            printf("4, So dien thoai cua sinh vien\n");
            printf("5, Sua tat ca thong tin\n");
            printf("Nhap lua chon cua ban : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("Nhap ID : ");
                scanf("%d",&newStudent.id);
                updateStudent(student,&count,newStudent,choice,index);
                showStudent(student,&count);
                break;
            case 2:
                printf("Nhap ten : ");
                fflush(stdin);
                fgets(newStudent.name,sizeof(newStudent.name),stdin);
                newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
                updateStudent(student,&count,newStudent,choice,index);
                showStudent(student,&count);
                break;
            case 3:
                printf("Nhap tuoi : ");
                scanf("%d",&newStudent.age);
                updateStudent(student,&count,newStudent,choice,index);
                showStudent(student,&count);
                break;
            case 4:
                printf("Nhap so dien thoai : ");
                fflush(stdin);
                fgets(newStudent.phoneNumber,sizeof(newStudent.phoneNumber),stdin);
                newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';
                updateStudent(student,&count,newStudent,choice,index);
                showStudent(student,&count);
                break;
            case 5:
                printf("Nhap ID : ");
                scanf("%d",&newStudent.id);
                printf("Nhap ten : ");
                fflush(stdin);
                fgets(newStudent.name,sizeof(newStudent.name),stdin);
                newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
                printf("Nhap tuoi : ");
                scanf("%d",&newStudent.age);
                printf("Nhap so dien thoai : ");
                fflush(stdin);
                fgets(newStudent.phoneNumber,sizeof(newStudent.phoneNumber),stdin);
                newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = '\0';
                updateStudent(student,&count,newStudent,choice,index);
                showStudent(student,&count);
                break;
            default:
                printf("Khong hop le, nhap lai!\n");
                break;
            }
            break;
        case 4:
            printf("Nhap vi tri sinh vien muon xoa : \n");
            scanf("%d",&index);
            deleteStudent(student,&count,index);
            showStudent(student,&count);
            break;
        case 5:
            printf("1, Tim kiem theo ID\n");
            printf("2, Tim kiem theo ten\n");
            printf("3, Tim kiem theo tuoi\n");
            printf("4, Tim kiem theo so dien thoai\n");
            printf("Nhap lua chon cua ban : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("Nhap ID : ");
                scanf("%d",&findStudent.id);
                searchStudent(student,&count,choice,findStudent);
                break;
            case 2:
                printf("Nhap ten : ");
                fflush(stdin);
                fgets(findStudent.name,sizeof(findStudent.name),stdin);
                findStudent.name[strcspn(findStudent.name, "\n")] = '\0';
                searchStudent(student,&count,choice,findStudent);
                break;
            case 3:
                printf("Nhap tuoi : ");
                scanf("%d",&findStudent.age);
                searchStudent(student,&count,choice,findStudent);
                break;
            case 4:
                printf("Nhap so dien thoai : ");
                fflush(stdin);
                fgets(findStudent.phoneNumber,sizeof(findStudent.phoneNumber),stdin);
                findStudent.phoneNumber[strcspn(findStudent.phoneNumber, "\n")] = '\0';
                searchStudent(student,&count,choice,findStudent);
                break;
            default:
                printf("Khong hop le, nhap lai!\n");
                break;
            }
            break;
        case 6:
            printf("1,Sap xep tang dan\n");
            printf("2,Sap xep giam dan\n");
            printf("Nhap lua chon cua ban : ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                sortStudent(student,&count,choice);
                showStudent(student,&count);
                break;
            case 2:
                sortStudent(student,&count,choice);
                showStudent(student,&count);
                break;
            default:
                printf("Khong hop le, nhap lai!\n");
                break;
            }
            break;
        case 7:
            printf("Tam biet!!");
            break;
        
        default:
            printf("Khong hop le, nhap lai!\n");
            break;
        }
    } while (choice != 7);
}

void showStudent(struct Student student[],int *count){
    printf("Danh sach sinh vien : \n");
    for (int i = 0; i < *count; i++)
    {
        printf("Thong tin sinh vien thu %d : \n",i+1);
        printf("ID : %d\n",student[i].id);
        printf("Ten sinh vien : %s\n",student[i].name);
        printf("Tuoi : %d\n",student[i].age);
        printf("So Dien Thoai : %s\n",student[i].phoneNumber);
        printf("_________________________\n");
    }   
}

void addStudent(struct Student student[], int *count,struct Student newStudent){
    student[(*count)++] = newStudent;
}

int idCheck(struct Student student[], int *count,struct Student newStudent){
    for (int i = 0; i < *count; i++)
    {
        if (newStudent.id == student[i].id)
        {
            printf("ID da ton tai, vui long nhap lai!\n");
            return 1;
        }
    }
    return 0;
}

void updateStudent(struct Student student[], int *count,struct Student newStudent,int choice,int index){
    switch (choice)
    {
    case 1:
        student[index-1].id = newStudent.id; 
        break;
    case 2:
        strcpy(student[index-1].name,newStudent.name);
        break;
    case 3:
        student[index-1].age = newStudent.age;
        break;
    case 4:
        strcpy(student[index-1].phoneNumber, newStudent.phoneNumber);
        break;
    case 5:
        student[index-1].id = newStudent.id;
        strcpy(student[index-1].name,newStudent.name);
        student[index-1].age = newStudent.age;
        strcpy(student[index-1].phoneNumber, newStudent.phoneNumber);
        break;
    }
}

void deleteStudent(struct Student student[], int *count,int index){
    for (int i = index-1; i < *count; i++)
    {
        student[i] = student[i+1];
    }
    (*count)--;
}

void searchStudent(struct Student student[], int *count,int choice,struct Student findStudent){
    int found = 0;
    char temp[100];
    switch (choice)
    {
        case 1:
            found = 0;
            for (int i = 0; i < *count; i++)
            {
                if (student[i].id == findStudent.id)
                {
                    printf("Thong tin sinh vien thu %d : \n",i+1);
                    printf("ID : %d\n",student[i].id);
                    printf("Ten sinh vien : %s\n",student[i].name);
                    printf("Tuoi : %d\n",student[i].age);
                    printf("So Dien Thoai : %s\n",student[i].phoneNumber);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("Khong tim thay sinh vien!\n");
            }
            break;
        case 2:
            found = 0;
            temp[0] = '\0';
            int lenght = strlen(findStudent.name);
            for (int i = 0; i < lenght ; i++)
            {
                findStudent.name[i] = toupper(findStudent.name[i]);
            }
            for (int i = 0; i < *count; i++)
            {
                strcpy(temp,student[i].name);
                for (int j = 0; j < strlen(temp); j++)
                {
                    temp[j] = toupper(temp[j]);
                }
                if (strcmp(temp,findStudent.name) == 0)
                {
                    printf("Thong tin sinh vien thu %d : \n",i+1);
                    printf("ID : %d\n",student[i].id);
                    printf("Ten sinh vien : %s\n",student[i].name);
                    printf("Tuoi : %d\n",student[i].age);
                    printf("So Dien Thoai : %s\n",student[i].phoneNumber);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("Khong tim thay sinh vien!\n");
            }
            break;
        case 3:
            found = 0;
            for (int i = 0; i < *count; i++)
            {
                if (student[i].age == findStudent.age)
                {
                    printf("Thong tin sinh vien thu %d : \n",i+1);
                    printf("ID : %d\n",student[i].id);
                    printf("Ten sinh vien : %s\n",student[i].name);
                    printf("Tuoi : %d\n",student[i].age);
                    printf("So Dien Thoai : %s\n",student[i].phoneNumber);
                }
            }
            if (!found)
            {
                printf("Khong tim thay sinh vien!\n");
            }
            break;
        case 4:
            found = 0;
            temp[0] = '\0';
            for (int i = 0; i < *count; i++)
            {
                strcpy(temp,student[i].phoneNumber);
                if (strcmp(temp,findStudent.phoneNumber) == 0)
                {
                    printf("Thong tin sinh vien thu %d : \n",i+1);
                    printf("ID : %d\n",student[i].id);
                    printf("Ten sinh vien : %s\n",student[i].name);
                    printf("Tuoi : %d\n",student[i].age);
                    printf("So Dien Thoai : %s\n",student[i].phoneNumber);
                    found = 1;
                }
            }
            if (!found)
            {
                printf("Khong tim thay sinh vien!\n");
            }
            break;
    }
}

void sortStudent(struct Student student[], int *count,int choice){
    struct Student temp;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < *count-1; i++) {
            for (int j = i+1; j < *count; j++) {
                if (strcmp(student[i].name, student[j].name) > 0) {
                    temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }
        break;
    case 2:
        for (int i = 0; i < *count-1; i++) {
            for (int j = i+1; j < *count; j++) {
                if (strcmp(student[i].name, student[j].name) < 0) {
                    temp = student[i];
                    student[i] = student[j];
                    student[j] = temp;
                }
            }
        }
        break;
    }
}