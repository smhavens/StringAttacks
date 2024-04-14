import json
 
# Opening JSON file
new_json = {}
count = 0

with open("weak_coding_json.json", 'r') as file:
    data = json.load(file)
    for i in data["ext"]:
        if i["_nodetype"] != "Typedef":
            new_json.update({count: i})
            count += 1
 
with open('weak_coding_notypedef.json', 'w') as newFile:
    json.dump(new_json, newFile)
    
print(json.dumps(new_json, indent = 4, sort_keys=True))
# returns JSON object as 
# a dictionary
# data = json.load(f)
 
# Iterating through the json
# list