import java.io.*;

public class Main {
	public static void main (String[] args) {
		try {
			File file = new File(args[0]);
			BufferedReader in = new BufferedReader(new FileReader(file));
			String line;
			int [] step = new int[3];
			while ((line = in.readLine()) != null) {
				int n = Integer.parseInt(line);
				step[0] = 1; step[1] = 2;
				if(n<=2) {
					System.out.println(step[n-1]);
					continue;
				}
				for(int i=1; i<n-1; i++) {
					step[2] = step[0] + step[1];
					step[0] = step[1];
					step[1] = step[2];
				}
				System.out.println(step[2]);
			}
			in.close();
		} catch (IOException e) {
			System.out.println("File Read Error: " + e.getMessage());
		}               
	}
}
