#include"Cluster.h"
#include<iostream>
using namespace std;
	int main() 
{
	Cluster cluster(8, 4, 32); // ��ʼ�����㼯Ⱥ���ܹ��� 8 �� CPU��4 �� GPU��32 GB �ڴ�
	cluster.submit_task({ 1, 1, 0, 4, 5 }); // �ύ������Ҫ 1 �� CPU��4 GB �ڴ棬Ԥ������ 5 ��
	cluster.submit_task({ 2, 1, 0, 4, 5 }); // �ύ������Ҫ 1 �� CPU��4 GB �ڴ棬Ԥ������ 5 ��
	cluster.submit_task({ 3, 0, 1, 4, 5 }); // �ύ������Ҫ 1 �� GPU��4 GB �ڴ棬Ԥ������ 5 ��
	cluster.submit_task({ 4, 0, 1, 4, 5 }); // �ύ������Ҫ 1 �� GPU��4 GB �ڴ棬Ԥ������ 5 ��
	cluster.submit_task({ 5, 2, 0, 8, 10 }); // �ύ������Ҫ 2 �� CPU��8 GB �ڴ棬Ԥ������ 10 ��
    cluster.submit_task({ 6, 9, 0, 1, 5 });// �ύ������Ҫ 9 �� CPU��1 GB �ڴ棬Ԥ������ 5 ��
	cluster.submit_task({ 7, 5, 3, 4, 6 });// �ύ������Ҫ 5 �� CPU��3 �� GPU��4 GB �ڴ棬Ԥ������ 6 ��
	cluster.submit_task({ 8, 0, 5, 5, 4 });// �ύ������Ҫ 5 �� GPU��5 GB �ڴ棬Ԥ������ 4��
	cluster.display_resource_usage(); // ��ʾ��Դʹ�����
	cluster.schedule(); // ��������
	cluster.display_resource_usage(); // ��ʾ��Դʹ�����
	return 0;
}
