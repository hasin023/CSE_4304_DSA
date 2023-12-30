#include <iostream>
#include <vector>
using namespace std;

// Definition of TradeNode representing a trade in the BST
struct TradeNode
{
    string tradeId;
    string stockSymbol;
    double transactionAmount;
    TradeNode *left;
    TradeNode *right;

    TradeNode(string id, string symbol, double amount)
        : tradeId(id), stockSymbol(symbol), transactionAmount(amount), left(nullptr), right(nullptr) {}
};

// Function to detect anomalies in stock trades using triplets in a BST
void detectAnomaliesInStockTrades(TradeNode *root, double targetSum, vector<string> &currentTriplet, vector<vector<string>> &result)
{
    if (!root)
    {
        return;
    }

    // Check if the current triplet is complete
    if (currentTriplet.size() < 3)
    {
        // Add the stock symbol to the current triplet
        currentTriplet.push_back(root->stockSymbol);
    }
    else
    {
        // If the current triplet is complete, check if it satisfies the target sum condition
        double tripletSum = 0.0;
        for (const string &symbol : currentTriplet)
        {
            tripletSum += root->transactionAmount;
        }

        if (tripletSum == targetSum)
        {
            // Add the current triplet to the result
            result.push_back(currentTriplet);
        }
    }

    // Recursively traverse left and right subtrees
    detectAnomaliesInStockTrades(root->left, targetSum, currentTriplet, result);
    detectAnomaliesInStockTrades(root->right, targetSum, currentTriplet, result);

    // Backtrack: Remove the last stock symbol from the current triplet
    currentTriplet.pop_back();
}

// Wrapper function to initialize the process
vector<vector<string>> findTripletsInBST(TradeNode *root, double targetSum)
{
    vector<string> currentTriplet;
    vector<vector<string>> result;

    // Start the recursive detection process
    detectAnomaliesInStockTrades(root, targetSum, currentTriplet, result);

    return result;
}

// Example usage
int main()
{
    // Example Trade Tree
    TradeNode *tradeTree = new TradeNode("A1", "AAPL", 100.0);
    tradeTree->left = new TradeNode("A2", "GOOGL", 150.0);
    tradeTree->right = new TradeNode("A3", "AMZN", 200.0);
    tradeTree->left->left = new TradeNode("A4", "AAPL", 50.0);
    tradeTree->left->right = new TradeNode("A5", "GOOGL", 120.0);
    tradeTree->right->left = new TradeNode("A6", "AAPL", 180.0);
    tradeTree->right->right = new TradeNode("A7", "MSFT", 300.0);

    double targetSum = 500.0;

    // Detect anomalies in stock trades and print the result
    vector<vector<string>> anomalies = findTripletsInBST(tradeTree, targetSum);

    cout << "Triplets with target sum " << targetSum << ":" << endl;
    for (const vector<string> &triplet : anomalies)
    {
        cout << "[";
        for (const string &symbol : triplet)
        {
            cout << symbol << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
