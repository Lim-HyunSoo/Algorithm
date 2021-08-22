import java.util.ArrayList;
import java.util.Collections;

public class SelectionSort {
	public static ArrayList<Integer> ssort(ArrayList<Integer> dataList) {
		int lowest;
		for(int stand = 0; stand < dataList.size() - 1; stand++) {
			lowest = stand;
			
			for(int index = stand + 1; index < dataList.size(); index++) {
				if(dataList.get(lowest) > dataList.get(index)) {
					lowest = index;
				}
			}
			Collections.swap(dataList,  lowest,  stand);
		}
		
		return dataList;
	}
	
	public static void main(String[] args) {
		ArrayList<Integer> testData = new ArrayList<Integer>();
		ArrayList<Integer> resultData = new ArrayList<Integer>();
		
		for (int i = 0; i < 10; i++) {
			testData.add((int)(Math.random() * 100));
		}
		
		System.out.println(testData);
		
		resultData = ssort(testData);
		
		System.out.println(resultData);
	}
}
