package com.hadoop.hdfs;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IOUtils;
import org.junit.Test;

// ͨ��IO����

public class IOToHDFS {

	
	// �ļ��ϴ�
	@SuppressWarnings("source")
	@Test
	public void putFileToHDFS() throws IOException, InterruptedException, URISyntaxException{
		// 0. ��ȡ�ļ�ϵͳ
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 1. ��ȡ����� hadoop��IO
		FSDataOutputStream fos = fs.create(new Path("/user/hadoop/output/nihao.txt"));
		
		// 2. ��ȡ������javaIO
		FileInputStream fis = new FileInputStream("nihao.txt");
		
		try{
			// 3. ���Խ�
			IOUtils.copyBytes(fis, fos, conf);
		}catch(Exception e){
			
		}finally{
			// 4. �ر���Դ
			IOUtils.closeStream(fis);
			IOUtils.closeStream(fos);
		}
	}

	// �����ļ�
	@Test
	public void getFileFromHDFS() throws IOException, InterruptedException, URISyntaxException{
		// 1  ��ȡ�ļ�ϵͳ
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2 ��ȡ������
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/output/nihao.txt"));
		
		// 3 ��ȡ�����
		FileOutputStream fos = new FileOutputStream("res/nihao.txt");
		
		try{
			// 4 ���Խ�
			IOUtils.copyBytes(fis, fos, conf);
		}catch(Exception e)
		{
			
		}finally
		{
			// 4. �ر���Դ
			IOUtils.closeStream(fis);
			IOUtils.closeStream(fos);
		}
	}
	
	// get a total block == 128MB
	@Test
	public void getABlockFromHDFS() throws IOException, InterruptedException, URISyntaxException
	{
		// 1  ��ȡ�ļ�ϵͳ
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2. ��������
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/input/hadoop-2.7.2.tar.gz"));  
		
		// 3. ���������
		FileOutputStream fos = new FileOutputStream("res/hadoop-2.7.2.tar.gz.part1");
		
		// 4. ���Խ�
		byte[] bytes = new byte[1024];
		for(int i = 0; i < 128*1024; i++)
		{
			fis.read(bytes);
			fos.write(bytes);
		}
		
		// 5. �ر���
		IOUtils.closeStream(fis);
		IOUtils.closeStream(fos);
	}
	
	
	// get a total block < 128MB
	@Test
	public void getPBlockFromHDFS() throws IOException, InterruptedException, URISyntaxException
	{
		// 1  ��ȡ�ļ�ϵͳ
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		// 2. ��������
		FSDataInputStream fis = fs.open(new Path("/user/hadoop/input/hadoop-2.7.2.tar.gz"));  
		
		// 3. ���������
		FileOutputStream fos = new FileOutputStream("res/hadoop-2.7.2.tar.gz.part2");
		
		// 4. ��λƫ�������ڶ�����׵�ַ
		fis.seek(1024*1024*128);
		
		// 5. ���Խ�
		IOUtils.copyBytes(fis, fos, conf);
		
		// 6. �ر���
		IOUtils.closeStream(fis);
		IOUtils.closeStream(fos);
	}
}
