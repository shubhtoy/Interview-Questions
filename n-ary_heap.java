public class heap_project
{
	public static class MaxHeap
	{
		private int[] heapArray;
		private int currentSize;
		private int maxSizeOfHeap;
		private int noOfChild;

		public MaxHeap(int sizeInput,int exponent)
		{
			noOfChild=(int)Math.pow(2,exponent);
			this.maxSizeOfHeap=sizeInput;
			this.currentSize=0;
			heapArray=new int[this.maxSizeOfHeap+1];
		}

		public void insert(int element)
		{
			int idx=currentSize;
			currentSize++;
			heapArray[idx]=element;
			while(idx>0)
			{
				int parentIdx=(idx-1)/noOfChild;
				if(heapArray[parentIdx]<heapArray[idx])
				{
					int temp=heapArray[parentIdx];
					heapArray[parentIdx]=heapArray[idx];
					heapArray[idx]=temp;
					idx=parentIdx;
				}
				else return;
			}
		}

		void maxHeapify(int idx)
		{
			int[] child=new int[noOfChild];
			
			while(true)
			{
				for(int i=0;i<noOfChild;i++)
				{
					child[i]=((noOfChild*idx+i+1)<currentSize)?(noOfChild*idx+i+1) : -1;
				}

				int maxChild=-1;
				int maxChildIdx=-1;

				for(int i=0;i<noOfChild;i++)
        		{
            		if (child[i] != -1 && heapArray[child[i]] > maxChild)
            		{
            		    maxChildIdx = child[i];
            		    maxChild = heapArray[child[i]];
            		}
        		}

        		if (maxChild == -1)	break;
 
        		if (heapArray[idx] < heapArray[maxChildIdx])
            	{
            		int temp=heapArray[idx];
            		heapArray[idx]=heapArray[maxChildIdx];
            		heapArray[maxChildIdx]=temp;
            	}
 
        		idx = maxChildIdx;
			
			}
		}

		public void popMax()
		{
			if(currentSize==0) return;
			heapArray[0]=heapArray[currentSize-1];
			currentSize--;
			maxHeapify(0);
		}
	}
}
