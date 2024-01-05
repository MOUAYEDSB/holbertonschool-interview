#!/usr/bin/python3

def canUnlockAll(boxes):
    if not boxes:
        return False
    
    keys = [0]  # List to keep track of keys
    visited = [False] * len(boxes)  # List to track visited boxes
    visited[0] = True  # Mark the first box as visited
    
    while keys:
        current_key = keys.pop()
        current_box = boxes[current_key]
        
        for key in current_box:
            if 0 <= key < len(boxes) and not visited[key]:
                visited[key] = True
                keys.append(key)
    
    return all(visited)
