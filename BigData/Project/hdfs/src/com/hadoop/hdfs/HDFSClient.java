package com.hadoop.hdfs;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.LocatedFileStatus;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.RemoteIterator;
import org.junit.Test;

public class HDFSClient {
	public static void main(String[] args) throws Exception{
// way 1
//		// 0.获取配置信息
//		Configuration configuration = new Configuration();
//		configuration.set("fs.defaultFS", "hdfs://PythonManCPP101:8020");
//		
//		// 1.获取文件系统
//		FileSystem fs = FileSystem.get(configuration);
//		
//		// 2. 拷贝本地数据到集群
//		fs.copyFromLocalFile(new Path("d:/xiyou.txt"),new Path("/user/hadoop/xiyou.txt"));
//		
//		// 3. 关闭fs
//		fs.close();
		
// way 2
		Configuration configuration = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), configuration, "hadoop");
		fs.copyFromLocalFile(new Path("d:/xiyou1.txt"),new Path("/user/hadoop/xiyou1.txt"));
		fs.close();
	}
	
	// 获取文件系统
	@Test
	public void getFileSystem() throws IOException, InterruptedException, URISyntaxException{
		
		// 0. 获取配置信息
		Configuration configuration = new Configuration();
		
		// 1. 获取文件系统
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), configuration, "hadoop");
		
		// 2. 打印文件系统
		System.out.println(fs.toString());
		
		// 3. 关闭资源
		fs.close();
	}
	
	// 上传文件
	@Test
	public void putFileToHDFS() throws IOException, InterruptedException, URISyntaxException{
		
		// 0. Get config infomation
		Configuration conf = new Configuration();
		
		// 1. get file system
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf, "hadoop");
		
		// 2. Execute the command to upload the file
		fs.copyFromLocalFile(true/*delete the resource*/,new Path("d:/xiyou2.txt"),new Path("/user/hadoop"));
		
		// 3. close the file system
		fs.close();
	}
	
	// 下载文件
	@Test
	public void getFileFromHDFS() throws IOException, InterruptedException, URISyntaxException
	{
		//0. Get configuration
		Configuration conf = new Configuration();
		
		//1. Get file system
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		//2. Execute the command to download file
		fs.copyToLocalFile(false,new Path("/user/hadoop/xiyou.txt"),new Path("res"));
		
		//3. close fs
		fs.close();
	}
	
	// 创建多级目录
	@Test
	public void mkDirAtHDFS() throws IOException, InterruptedException, URISyntaxException{
		//0. Get configuration
		Configuration conf = new Configuration();
		
		//1. Get file system
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
		
		//2. Execute makedir
		fs.mkdirs(new Path("/user/hadoop/mm"));
		
		//3. close fs
		fs.close();
	}
	
	// 更改文件名
	@Test
	public void renameAtDHFS() throws IOException, InterruptedException, URISyntaxException
	{
		//0. Get configuration
		Configuration conf = new Configuration();
				
		//1. Get file system
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
				
		//2. Execute rename
		fs.rename(new Path("/user/hadoop/xiyou.txt"), new Path("/user/hadoop/xxxxnimei.txt"));
				
		//3. close fs
		fs.close();
	}
	
	@Test
	public void readFileAtDHFS() throws IOException, InterruptedException, URISyntaxException
	{
		//0. Get configuration
		Configuration conf = new Configuration();
				
		//1. Get file system
		FileSystem fs = FileSystem.get(new URI("hdfs://PythonManCPP101:8020"), conf,"hadoop");
				
		//2. Execute rename
		RemoteIterator<LocatedFileStatus> listFiles = fs.listFiles(new Path("/"), true);
		while(listFiles.hasNext())
		{
			LocatedFileStatus status = listFiles.next();
			// 打印文件名
			System.out.println(status.getPath().getName());
			// 打印块的大小
			System.out.println(status.getBlockSize());
			// 打印内容的长度
			System.out.println(status.getLen());
			// 打印文件权限
			System.out.println(status.getPermission());
			
			System.out.println("-------------------------");
		}
		//3. close fs
		fs.close();
	}

}
