///*
// * vector_func.cpp
// *
// *  Created on: 2014年11月14日
// *      Author: Ella
// */
//#include <iostream>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//int main(void)
//{
////	https://www.youtube.com/watch?v=Cq1h1KPoGBU&list=UUoGd-PUiT-pZMePaBNRcAcA&index=25
////	Format:vector<DataType> nameOfVector
////	myVector.push_back(value) ==> adds an element to the END of the vector <also resize it)
////	myVector.at(index) ==> return element at specified index number
////	myVector.size() ==> returns an unsigned int equal to the number of elements
////	myVector.begin() ==> reads vector from first element (index 0)
////	myVector.insert(myVector.begin() + integer, new value) ==> adds element BEFORE specified index number
////	myVector.erese(myVector.begin() + integer) ==> removes element AT specified index number
////	myVector.clear() ==> removes all elements in vector
////	myVector.empty() ==> returns boolean value if weather vector is empty
//	vector<int> myVector;
//
//	myVector.push_back(3);
//
////定义及初始化
//
//    vector<int> v;//只定义了v，没有分配内存空间
//    vector<int> ve(2);//定义并分配了2int空间的ve，缺省为0
//    vector<int> vec(3,4);//定义并初始化了3个4的vec
//    cout<<v.size()<<" "<<ve.size()<<" "<<vec.size()<<endl;//0 2 3
//    cout<<"ve:"<<ve[0]<<" "<<ve[1]<<endl;//ve: 0 0
//    cout<<"vec:"<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;//vec: 4 4 4
//    v.assign(3,8);//赋值3个8
//    ve.assign(vec.begin(),vec.end());//赋值3个4
//    for (int i=0;i<v.size();i++)
//        cout<<v[i]<<" "; //8 8 8
//    cout<<endl;
//    for (int i=0;i<ve.size();i++)
//        cout<<ve[i]<<" ";//4 4 4
//    cout<<endl;
//    ve.assign(0,0);//赋值0个0，且可以看出它的内存是变化的.此为空
//    for (int i=0;i<ve.size();i++)
//        cout<<ve[i]<<" ";//为空
//    cout<<endl;
//}
////增加删除元素
//void test1()
//{
//    vector<char> v(2,'A');
//    v.push_back('B');//在尾部加入一个数据
//    cout<<v[0]<<" "<<v[1]<<' '<<v[2]<<endl;//A A B
//    v.pop_back();//删除最后一个数据
//    v.insert(v.begin()+1,'C');//在第二个位置上插入了'C'
//    v.insert(v.begin(),2,'D'); //在第一个第二个位置上分别插入'C'
//    v.insert(v.end(),v.begin(),v.end());//在其末端插入了其之前的所有元素，等于复制了
//    for (int i=0;i<v.size();i++)
//        cout<<v[i]<<" "; //D D A C A D D A C A
//    cout<<endl;
//
//    v.erase(v.begin());//删除第一个元素
//    for (int i=0;i<v.size();i++)
//        cout<<v[i]<<" "; //D A C A D D A C A
//    cout<<endl;
//    v.erase(v.begin()+1,v.end()-1);//留下两端的元素，删除中间的元素
//    for (int i=0;i<v.size();i++)
//        cout<<v[i]<<" "; //D A
//    cout<<endl;
//    v.clear();//删除全部
//    for (int i=0;i<v.size();i++)
//        cout<<v[i]<<" "; //为空
//    cout<<endl;
//}
////访问获取元素
//void test2()
//{
//    string str[]={"one","two","three","four","five","six"};
//    vector<string> ve;
//    for(int i=0;i<6;i++)
//    {
//        ve.push_back(str[i]);
//        cout<<ve[i]<<" ";//通过索引值i来进行访问,使用的是数组的形式，当然不能越界
//    }
//    cout<<endl;
//    for(int i=0;i<6;i++)
//    {
//        cout<<ve.at(i)<<" ";//使用at()通过i来进行访问，也不能越界。若越界，在调试时，会抛出异常；在运行时直接弹出错误
//    }
//    cout<<endl;
//    cout<<ve.front()<<endl;//one //返回第一个元素的引用
//    cout<<ve.back()<<endl;//six //返回最后一个元素的引用
//}
////返回迭代器
//void test3()
//{
//    vector<int>ve(4);
//    ve[0]=0;ve[1]=1;ve[2]=2;ve[3]=3;
//    cout<<ve[0]<<" "<<ve[1]<<" "<<ve[2]<<" "<<ve[3]<<endl;
//    vector<int>::iterator iter;//定义一个迭代器iter
//    iter=ve.begin();//返回一个iterator，它指向vector第一个元素
//    cout<<*iter<<endl;//0
//     iter=ve.end();//返回一个iterator，它指向vector最末尾元素的下一个位置(它不是末尾元素)
//     //cout<<*iter<<endl;//会出现错误
//     cout<<*(iter-1)<<endl;//3 用此方法访问末尾元素
//     vector<int>::reverse_iterator reIter;//定义一个反向的迭代器
//     reIter=ve.rbegin();//返回一个方向iterator，它指向vector末尾元素
//    cout<<*reIter<<endl;//3
//    reIter=ve.rend();//返回一个方向iterator，它指向vector第一个元素之前的位置(它是不存在的)
//    cout<<*(reIter-1)<<endl;//0  用此方法访问第一个元素
//}
////取得、设置长度、容量
//void test4()
//{
//    vector<string> ve(8);
//    cout<<ve.size()<<endl;//8
//    cout<<ve.max_size()<<endl;//134217727，10737441823
//    cout<<ve.capacity()<<endl;//8
//    cout<<ve.empty()<<endl;//0,说明不为空，因为默认值是0
//
//    ve.assign(12,"3");
//    cout<<ve.size()<<endl;//12
//    cout<<ve.max_size()<<endl;//134217727(string),10737441823(int)
//    cout<<ve.capacity()<<endl;//12
//    cout<<ve.empty()<<endl;//0
//
//    ve.assign(1,"003");
//    cout<<ve.size()<<endl;//1  返回vector当前持有元素的个数
//    cout<<ve.max_size()<<endl;//他的最大个数与数据类型有关
//    cout<<ve.capacity()<<endl;//12 容量 取得vector目前可容纳的最大元素个数。这个方法与存储配置有关，它通常只会增加，不会因为元素被删除而随之减少
//    cout<<ve.empty()<<endl;//0 为空时，返回true
//
//    ve.resize(15,"W");//改变vector目前持有元素的个数
//    cout<<ve.size()<<endl;//15
//    cout<<ve.max_size()<<endl;//134217727(string),10737441823(int)
//    cout<<ve.capacity()<<endl;//18
//    cout<<ve.empty()<<endl;//0
//
//    ve.reserve(5);//如有必要，可改变vector的容量大小(只会增加，减少不起作用)
//    cout<<ve.size()<<endl;//15
//    cout<<ve.max_size()<<endl;//134217727(string),10737441823(int)
//    cout<<ve.capacity()<<endl;//18 当ve.reserve(35);则输出35；则说明容量capacity只会增加不会减少
//    cout<<ve.empty()<<endl;//0
//}
////遍历vector
//void test5()
//{
//    vector<int> vec;
//    for (int i=0;i<10;i++)
//    {
//        vec.push_back(i);
//    }
//    for (int i=0;i<vec.size();i++)
//        cout<<vec[i]<<" ";
//    cout<<endl;
//
//    vector<int>::iterator iter;
//    for (iter=vec.begin();iter!=vec.end();iter++)
//        cout<<*iter<<" ";
//    cout<<endl;
//
//    vector<int>::reverse_iterator reIter;
//    for (reIter=vec.rbegin();reIter!=vec.rend();reIter++)
//        cout<<*reIter<<" ";//9 8 7 6 5 4 3 2 1 0
//    cout<<endl;
//
//    vector<int>::reverse_iterator revIter;
//    for (revIter=vec.rend()-1;revIter!=vec.rbegin();revIter--)
//        cout<<*revIter<<" ";//0 1 2 3 4 5 6 7 8 //有点残缺
//    cout<<endl;
//}
//void Test(char h)
//{
//    cout<<"press key===="<<h<<endl;
//    switch(h)
//    {
////    case '0':  test0();break;
//    case '1':  test1();break;
//    case '2':  test2();break;
//    case '3':  test3();break;
//    case '4':  test4();break;
//    case '5':  test5();break;
//    case 27:
//    case 'q':exit(0);break;
//    default:cout<<"default "<<h<<endl;break;
//    }
//}
//void main()
//{
//    while(1)
//    {
//        Test(getch());
//    }
//}
////该代码片段来自于: http://www.sharejs.com/codes/cpp/6208
//
//
//}
//
//
//
