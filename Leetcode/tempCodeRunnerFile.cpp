class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int left = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas[i] < cost[i])
                continue;
            int flag = i;
            for (int j = i; j < i + gas.size(); j++)
            {
                int index;
                if (j >= gas.size())
                    index = j - gas.size();
                else
                    index = j;
                left += gas[index];
                left -= cost[index];
                if (left < 0)
                {
                    flag = -1;
                }
            }
            if (flag != -1)
                return flag;
        }
        return -1;
    }
};