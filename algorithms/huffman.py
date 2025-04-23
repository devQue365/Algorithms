import heapq # for min heap priority queue

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        # add additional detail of left and right nodes
        self.left = None
        self.right = None
    def __lt__(self, other):
        return self.freq < other.freq

def huffman_encoding(char_freqs):
    # create a heap data structure
    heap = [Node(char, freq) for char,freq in char_freqs.items()]
    # heapify operation
    heapq.heapify(heap)
    # Now the main operation
    while(len(heap) > 1):
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        # push the merged node into heap
        heapq.heappush(heap, merged)
    return heap[0]
def generate_codes(node, code = "", codes = {}):
    if node:
        # check for external nodes
        if node.char is not None:
            codes[node.char] = code
        # Recursion
        generate_codes(node.left, code + "0", codes)
        generate_codes(node.right, code + "1", codes)
    return codes

char_freqs = {
    'a': 5,
    'b': 9,
    'c': 12,
    'd': 13,
    'e': 16,
    'f': 45
}

# get root node
root = huffman_encoding(char_freqs)
# generate codes
codes = generate_codes(root)
print(codes)