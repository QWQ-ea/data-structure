#pragma once
//���㼯Ⱥϵͳ
#include<iostream>
#include"LinkedQueue.h"
#include<iomanip>
using namespace std;
class Cluster {
	private:
		LinkedQueue<Task> waiting_queue; // �ȴ�����
		LinkedQueue<Task> running_queue; // ���ж���
		LinkedQueue<Task> finished_queue; // ����ɶ���
		int cpu_total; // CPU ����
		int gpu_total; // GPU ����
		int memory_total; // �ڴ��ܴ�С
		int cpu_used; // CPU ��ʹ����
		int gpu_used; // GPU ��ʹ����
		int memory_used; // �ڴ���ʹ�ô�С
		int id_counter; // ���� ID ������
		int* _cpu;  //cpuָ������
		int* _gpu;  //gpuָ������
		int* _memory; //�ڴ�ָ������
public:
	Cluster(int _cpu_total, int _gpu_total, int _memory_total);
	void submit_task(Task task);
	void schedule();
	void display_resource_usage();
};

Cluster::Cluster(int _cpu_total, int _gpu_total, int _memory_total)
	: cpu_total(_cpu_total), gpu_total(_gpu_total), memory_total(_memory_total),
	cpu_used(0), gpu_used(0), memory_used(0), id_counter(0) 
	{
		_cpu=new int[cpu_total];
		for(int i=0;i<cpu_total;i++) _cpu[i]=0;
		_gpu=new int[gpu_total];
		for(int i=0;i<gpu_total;i++) _gpu[i]=0;
		_memory=new int[memory_total];
		for(int i=0;i<memory_total;i++) _memory[i]=0;
	}
// �ύ����
void Cluster::submit_task(Task task) {
	task.id = ++id_counter;
	waiting_queue.push(task);
	cout << "���� ID Ϊ " << task.id << " ���������ύ" << endl;
}

// ��������
void Cluster::schedule() {
	// �����ȴ����У�������㹻����Դ�ͽ�����������ж���
	int n=waiting_queue.size();
	while(n!=0){
	while (!waiting_queue.empty()&&n>0) {
		Task task = waiting_queue.front();
		if (cpu_used + task.cpu <= cpu_total && gpu_used + task.gpu <= gpu_total &&
			memory_used + task.memory <= memory_total) {
			// ���¿�����Դ����
			int a=cpu_used,b=gpu_used,c=memory_used;
			for(int i=0;i<task.cpu;i++) {_cpu[a]=task.id;a++;}
			for(int i=0;i<task.gpu;i++) {_gpu[b]=task.id;b++;}
			for(int i=0;i<task.memory;i++) {_memory[c]=task.id;c++;}
			// ������ӵȴ������Ƶ����ж���
			cpu_used += task.cpu;
			gpu_used += task.gpu;
			memory_used += task.memory;
			waiting_queue.pop();
			running_queue.push(task);
			cout << "���� ID Ϊ " << task.id << " �������Ѽ������ж���" << endl;
			n--;
			display_resource_usage();
		}
		else {
			// �����Դ���㣬�����������ȴ�����β��
			task = waiting_queue.front();
			if(task.cpu>cpu_total||task.gpu>gpu_total||task.memory>memory_total)
			{cout<<"���� ID Ϊ "<<task.id<<"������������Դ��������Դ"<<",���ӵȴ��������Ƴ�������"<<endl;
				waiting_queue.pop();
				system("pause");
				continue;
			}
			waiting_queue.pop();
			waiting_queue.push(task);
			cout << "���� ID Ϊ " << task.id << " ����������Դ���㱻�����ȴ�����β��" << endl; 
			n--;
		}
	}
  int a=0,b=0,c=0;
	while (!running_queue.empty()) {
		Task task = running_queue.front();
	for(int i=0;i<task.cpu;i++) {_cpu[a]=0;a++;}
	for(int i=0;i<task.gpu;i++) {_gpu[b]=0;b++;}
	for(int i=0;i<task.memory;i++) {_memory[c]=0;c++;}
		running_queue.pop();
		finished_queue.push(task);
		// ���¿�����Դ����
		cpu_used -= task.cpu;
		gpu_used -= task.gpu;
		memory_used -= task.memory;
		cout << "���� ID Ϊ " << task.id << " �����������" << endl;
		display_resource_usage();
	}
	n=waiting_queue.size();
	}
}
// ��ʾ��Դʹ�����
void Cluster::display_resource_usage() {
	cout << "CPU ʹ�������" << cpu_used << "/" << cpu_total << " ��" << endl;
	cout << "GPU ʹ�������" << gpu_used << "/" << gpu_total << " ��" << endl;
	cout << "�ڴ�ʹ�������" << memory_used << "/" << memory_total << " GB" << endl;
	int a=cpu_total,b=gpu_total,c=memory_total;
	int n=(a>b)?((a>c)?a:c):((b>c)?b:c);
	for(;n>0;n--)
	{
	if(a>0) {if(_cpu[cpu_total-a]==0) cout<<"CPU"<<cpu_total-a<<":"<<left<<setw(12)<<"����";else cout<<"CPU"<<cpu_total-a<<":"<<"����"<<_cpu[cpu_total-a]<<left<<setw(7)<<"ʹ��";a--;}
	else cout<<right<<setw(17)<<setfill(' ')<<" ";
    if(b>0) {if(_gpu[gpu_total-b]==0) cout<<"GPU"<<gpu_total-b<<":"<<left<<setw(12)<<"����";else cout<<"GPU"<<gpu_total-b<<":"<<"����"<<_gpu[gpu_total-b]<<left<<setw(7)<<"ʹ��";b--;}
	else cout<<right<<setw(17)<<setfill(' ')<<" ";
	if(c>0) {if(_memory[memory_total-c]==0) cout<<"MEMORY"<<memory_total-c<<":"<<left<<setw(12)<<"����";else cout<<"MEMORY"<<memory_total-c<<":"<<"����"<<_memory[memory_total-c]<<left<<setw(7)<<"ʹ��";c--;}
	cout<<endl;
	}
}
