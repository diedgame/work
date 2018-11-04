package Book;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Library {
	public static int getcount() {
		int count = 0;
		for (int i = 0; i < 100; i++) {
			count++;
			if (bookstore[i] == null)
				break;
		}
		return count;
	}

	public static void showall() {
		int i = 0;
		while (bookstore[i] != null) {
			System.out.println("第" + (i + 1) + "篇");
			System.out.println(bookstore[i].getKind());
			System.out.println(bookstore[i].getAuthor());
			System.out.println(bookstore[i].getTitle());
			System.out.println(bookstore[i].getJournal());
			System.out.println(bookstore[i].getBooktitle());
			System.out.println(bookstore[i].getYear());
			i++;
		}
	}

	public static void show(int i) {
		System.out.println("第" + (i + 1) + "篇");
		System.out.println(bookstore[i].getKind());
		System.out.println(bookstore[i].getAuthor());
		System.out.println(bookstore[i].getTitle());
		System.out.println(bookstore[i].getJournal());
		System.out.println(bookstore[i].getBooktitle());
		System.out.println(bookstore[i].getYear());

	}

	public static void search() {
		System.out.println("请输入文献作者名：");
		s = new Scanner(System.in);

		String a = s.nextLine();
		for (int i = 0; i < getcount() - 1; i++) {
			if (a.equals(bookstore[i].getAuthor()))
				show(i);
			else
				System.out.println("无该文献");

		}

	}

	public static int searchyear(int a) {

		int q = 120;

		for (int i = 0; i < getcount() - 1; i++) {
			if (a == bookstore[i].getYear())
				q = i;

		}
		return q;

	}

	public static void judge() {
		System.out.println("请输入两位作者名字");
		s = new Scanner(System.in);
		String a = s.nextLine();
		String b = s.nextLine();
		for (int i = 0; i < getcount() - 1; i++) {
			if (bookstore[i].getAuthor().indexOf(a) != -1 && bookstore[i].getAuthor().indexOf(b) != -1) {
				System.out.println("二位作者在" + bookstore[i].getTitle() + "中发表过文章");
			}

		}

	}

	public static void paixu(){
		List<Integer>list=new ArrayList<>();
		for (int i = 0; i < getcount() - 1; i++)
		{list.add(bookstore[i].getYear());}
		Collections.sort(list);
		for (int i = 0; i < getcount() - 1; i++)
		{
			show(searchyear(list.get(i)));
			
		}
		
	}

	public static Scanner s = null;
	public static Publication[] bookstore = new Publication[100];

	public static void main(String[] args) {

		Publication a = new Publication("article",
				"Anson, Eric and Rosenberg, Russell and Agada, Peter and Kiemel, Tim and Jeka, John",
				" Does visual feedback during walking result in similar improvements in trunk control for young and older healthy adults?",
				" Journal of neuroengineering and rehabilitation", null,  2013);
		Publication b = new Publication("inproceedings",
				"Azmandian, Mahdi and Grechkin, Timofey and Bolas, Mark and Suma, Evan",
				"Physical space requirements for redirected walking: how size and shape affect performance", null,
				"Proceedings of the 25th International Conference on Artificial Reality and Telexistence and 20th Eurographics Symposium on Virtual Environments",
				2015);
		bookstore[0] = a;
		bookstore[1] = b;
		System.out.println("*******************************************************************");
		System.out.println(
				"请选择功能：\n1.显示所有文献\n2.寻找指定文献\n3.判断作者是否在同一文献中发表过文章\n4.按照年份排序文章\n*******************************************************************");
		s = new Scanner(System.in);
		String key = s.nextLine();
		switch (key) {
		case "1":
			showall();

			break;

		case "2":
			search();
			break;
		case "3":
			judge();
			break;
		case "4":
			paixu();
			break;
		}
	}

}
