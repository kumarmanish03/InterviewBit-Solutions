// Manish Kumar, IIIT Allahabad
// Easy

https://www.interviewbit.com/problems/maximum-level-sum/

// Level order travelsal
int Solution::solve(TreeNode *A)
{
  if (!A)
    return 0;
  int maxm_sum = INT_MIN;
  queue<TreeNode *> q;
  q.push(A);
  while (!q.empty())
  {

    // sum of all elemets of the level
    int num = q.size();
    int temp_sum = 0;
    while (num--)
    {
      TreeNode *temp = q.front();
      q.pop();
      temp_sum += temp->val;
      // Pushing valid next-level elements
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    maxm_sum = max(maxm_sum, temp_sum);
  }

  return maxm_sum;
}
