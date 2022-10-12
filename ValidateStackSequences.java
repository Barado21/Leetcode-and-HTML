
class Solution{
  public boolean validateStackSequences(int[] pushed, int[] popped) {

          Stack<Integer> stack = new Stack<Integer>();
          int i=0,j=0, n = pushed.length;

          while(i<n && j<n){

              stack.push(pushed[i]);

              while(!stack.isEmpty() && stack.peek()==popped[j]){
                  stack.pop();
                  j++;
              }
              i++;
          }
          return stack.isEmpty();

    }
}
