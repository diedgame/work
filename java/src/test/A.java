package test;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class A {


	public static void main(String[] args) throws IOException {
		final String filepath="src/five/Card.java";
		final String filepath2="src/test/B.java";
		File file=new File(filepath);
		File file2=new File(filepath2);
		FileInputStream in=new FileInputStream(file);
		byte bytes[]=new byte[10000];
		in.read(bytes);
		String a=new String(bytes);
		System.out.println(a);
		
		
		FileOutputStream out=new FileOutputStream(file2);
		out.write(bytes);
		
		
		
		
		
		

	}

	
}
