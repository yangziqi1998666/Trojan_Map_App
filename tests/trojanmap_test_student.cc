#include <map>
#include <vector>
#include <unordered_set>
#include "gtest/gtest.h"
#include "src/lib/trojanmap.h"

TEST(TrojanMapStudentTest, Test1) {
    TrojanMap trojan;
    trojan.CreateGraphFromCSVFile();
    //// 1. Autocomplete
    // Test the case for "Ta"
    auto names = trojan.Autocomplete("Ta");
    std::unordered_set<std::string> gt1 = {"Target", "Tap Two Blue"};
    int success = 0;
    for (auto& n: names) {
        EXPECT_EQ(gt1.count(n) > 0, true);
        if (gt1.count(n) > 0){
            success++;
        }
    }
    EXPECT_EQ(success, gt1.size());
    // Test the lower case "ta"
    names = trojan.Autocomplete("ta");
    gt1 = {"Target", "Tap Two Blue"};
    success = 0;
    for (auto& n: names) {
        EXPECT_EQ(gt1.count(n) > 0, true);
        if (gt1.count(n) > 0){
            success++;
        }
    }
    EXPECT_EQ(success, gt1.size());
    // Test the lower and upper case "tA"
    names = trojan.Autocomplete("tA");
    gt1 = {"Target", "Tap Two Blue"};
    success = 0;
    for (auto& n: names) {
        EXPECT_EQ(gt1.count(n) > 0, true);
        if (gt1.count(n) > 0){
            success++;
        }
    }
    EXPECT_EQ(success, gt1.size());
    // Test the upper case "TA"
    names = trojan.Autocomplete("TA");
    gt1 = {"Target", "Tap Two Blue"};
    success = 0;
    for (auto& n: names) {
        EXPECT_EQ(gt1.count(n) > 0, true);
        if (gt1.count(n) > 0){
            success++;
        }
    }
    EXPECT_EQ(success, gt1.size());


    //// 2. GetPosition
    // Test the position of McAlister Field
    std::pair<double, double> output2(34.0265527,-118.2827244);
    EXPECT_EQ(trojan.GetPosition("McAlister Field"),output2);

    output2 = std::make_pair(34.0245381,-118.2845934);
    EXPECT_EQ(trojan.GetPosition("Kaitlyn"),output2);

    output2 = std::make_pair(34.0246375,-118.2853001);
    EXPECT_EQ(trojan.GetPosition("Coffee Bean2"),output2);




    //// 3. CalculateShortestPath
    std::string loc1;
    std::string loc2;
    std::vector<std::string> output3;
    // test1
    loc1 = "Ralphs";
    loc2 = "CVS" ;
    output3 = {"2578244375","5559640911","6787470571","6808093910","6808093913","6808093919","6816831441","6813405269","6816193784","6389467806","6816193783","123178876","2613117895","122719259","6807243574","6807243576","213332111","441895337","441895335","122719255","2613117893","6813405231","122719216","6813405232","4015372486","7071032399","4015372485","6813379479","5237381975","4399698012","4399698013","4399698011","4399698010","123044712","4399698009","4399698008","123005253","6813379513","6813379517","6813379521","123327627","6807200379","123327636","4141790934","6813379531","6285409682","6787803628","6813379501","3088548446"};
    EXPECT_EQ(trojan.CalculateShortestPath_Dijkstra(loc1,loc2),output3);
    EXPECT_EQ(trojan.CalculateShortestPath_Bellman_Ford(loc1,loc2),output3);
    // test2
    loc1 = "Ralphs";
    loc2 = "Subway";
    output3 = {"2578244375","5559640911","6787470571","6808093910","6808093913","6808093919","6816831441","6813405269","6816193784","6389467806","6816193783","123178876","2613117895","122719259","2613117861","6817230316","3642819026","6817230310","7811699597","5565967545","123318572","6813405206","6813379482","544672028","21306059","6813379476","6818390140","63068610","6818390143","7434941012","4015423966","5690152766","6813379440","6813379466","21306060","6813379469","6813379427","123005255","6807200376","6807200380","6813379451","6813379463","123327639","6813379460","4141790922","4015423963","1286136447","1286136422","4015423962","6813379494","63068643","6813379496","123241977","4015372479","4015372477","1732243576","6813379548","4015372476","4015372474","4015372468","4015372463","6819179749","1732243544","6813405275","348121996","348121864","6813405280","1472141024","6813411590","216155217","6813411589","1837212103","1837212101","6820935911","932416162","4060015482","4020099365","6820972450","1732243549","6820972451","122436252","1836105028","4060015481","4020099358","6814990127","7867091027","7867091030","6226313827","932378219","6814990112","1870795293","6814990128","4060015480","1870795287","4020099348","1870795282","1870787389","1870795272","1870795261","1870795259","1855150081","1759017530"};
    EXPECT_EQ(trojan.CalculateShortestPath_Dijkstra(loc1,loc2),output3);
    EXPECT_EQ(trojan.CalculateShortestPath_Bellman_Ford(loc1,loc2),output3);

    //// 4. Travelling salesman problem
    // test1
    std::vector<std::string> input4;
    std::vector<std::string> output4_back;
    std::vector<std::string> output4_2opt;
    input4={"6813405266","4012842278","7561883968","604243558"};
    output4_back={"6813405266","4012842278","7561883968","604243558","6813405266"};
    output4_2opt={"6813405266","4012842278","7561883968","604243558","6813405266"};
    auto result_back=trojan.TravellingTrojan(input4);
    auto result_2opt=trojan.TravellingTrojan_2opt(input4);
    // Backtracking
    bool flag = false;
    if(output4_back==result_back.second[result_back.second.size()-1])
        flag=true;
    std::reverse(output4_back.begin(),output4_back.end());
    if(output4_back==result_back.second[result_back.second.size()-1])
        flag=true;
    EXPECT_EQ(flag,true);
    // 2-opt
    flag = false;
    if(output4_2opt==result_2opt.second[result_2opt.second.size()-1])
    flag=true;
    std::reverse(output4_2opt.begin(),output4_2opt.end());
    if(output4_2opt==result_2opt.second[result_2opt.second.size()-1])
    flag=true;
    EXPECT_EQ(flag,true);

    // test2
    input4 = {"4060096188",
              "4012726928",
              "6807935213",
              "1790748059",
              "1878000349"};
    output4_back={"4060096188",
                  "4012726928",
                  "6807935213",
                  "1790748059",
                  "1878000349",
                  "4060096188"};
    output4_2opt={"4060096188",
                  "4012726928",
                  "6807935213",
                  "1790748059",
                  "1878000349",
                  "4060096188"};
    result_back=trojan.TravellingTrojan(input4);
    result_2opt=trojan.TravellingTrojan_2opt(input4);
    // Backtracking
    flag = false;
    if(output4_back==result_back.second[result_back.second.size()-1])
        flag=true;
    std::reverse(output4_back.begin(),output4_back.end());
    if(output4_back==result_back.second[result_back.second.size()-1])
        flag=true;
    EXPECT_EQ(flag,true);

    std::cout << "testing " << std::endl;
    input4 = {"1873056015", "6905329551", "213332060", "1931345270","1862312636", "7424270441", "67666219", "4015405548", "4015203110", "6807439002"};
    trojan.TravellingTrojan_genetic(input4);
    //std::cout << "ans:" << result_back.first << std::endl;

    //// 5. Cycle Detection
    std::vector<double> square;
    // test1
    square = {-118.299, -118.264, 34.032, 34.011};
    EXPECT_EQ(trojan.CycleDetection(square),true);
    // test2
    square = {-118.290919, -118.282911, 34.02235, 34.019675};
    EXPECT_EQ(trojan.CycleDetection(square),false);
    // test3
    square = {-118.291, -118.282, 34.023, 34.020};
    EXPECT_EQ(trojan.CycleDetection(square),true);
    // test4
    square = {-118.551, -118.023, 34.044, 34.001};
    EXPECT_EQ(trojan.CycleDetection(square),true);

    //// 6. Topological Sort
    std::vector<std::string> output6;
    std::vector<std::string> location_names;
    std::vector<std::vector<std::string>> dependencies;
    // test1
    location_names = {"USC Parking", "Sunlife Smoothies", "Kaitlyn"};
    dependencies = {{"USC Parking","Sunlife Smoothies"}, {"USC Parking","Kaitlyn"}, {"Sunlife Smoothies","Kaitlyn"}};
    output6 ={"USC Parking","Sunlife Smoothies","Kaitlyn"};
    EXPECT_EQ(trojan.DeliveringTrojan(location_names, dependencies),output6);
    // test2
    location_names = {"USC Parking", "Sunlife Smoothies", "restaurant seating","Lawn"};
    dependencies = {{"USC Parking","Sunlife Smoothies"}, {"USC Parking","restaurant seating"}, {"Sunlife Smoothies","restaurant seating"},{"restaurant seating","Lawn"}};
    output6 ={"USC Parking","Sunlife Smoothies","restaurant seating","Lawn"};
    EXPECT_EQ(trojan.DeliveringTrojan(location_names, dependencies),output6);
    // test3
    location_names = {"BBCM", "Sunlife Smoothies", "USC Village Gym"};
    dependencies = {{"BBCM","Sunlife Smoothies"}, {"BBCM","USC Village Gym"}, {"Sunlife Smoothies","USC Village Gym"}};
    output6 ={"BBCM","Sunlife Smoothies","USC Village Gym"};
    EXPECT_EQ(trojan.DeliveringTrojan(location_names, dependencies),output6);


    //// 7. Find the K closest points
    std::string name;
    std::vector<std::string> output7;
    // Find 5 closest points to Ralphs
    name = "Ralphs";
    output7 = {
      "3724125231", "358791507", "7158047272", "358828789", "358794109"};
    EXPECT_EQ(trojan.FindKClosestPoints(name, 5),output7);
    // Find 10 closest points to PED
    name = "PED";
    output7 = { "4536993737", "5229911604", "2305853438", "5229911615",
                "2305440181", "4141781780", "2305853437", "6814620863", "4089614983", "4089614986"};
    EXPECT_EQ(trojan.FindKClosestPoints(name, 10),output7);
    // Find 6 closest points to Lyons Center
    name = "Lyons Center";
    std::vector<std::string> items = trojan.FindKClosestPoints(name, 6);
    output7 = {"6042966366", "6047234446", "368172334", "4141781780", "6042956074", "5567721536"};
    EXPECT_EQ(trojan.FindKClosestPoints(name, 6),output7);

}

