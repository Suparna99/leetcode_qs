class TrieNode
    attr_accessor :children , :end
    def initialize()
         @children = {}
         @end = false
    end 
end


class Trie
    attr_accessor :root 
    
   def initialize()
       @root = TrieNode.new
   end
    
    def add(w)
        w = w.reverse
        r = @root
        w.each_char do |c|
            r.children[c] ||= TrieNode.new
            r = r.children[c]
        end
        r.end = true
    end
    
    def search(arr = [])
        r = @root
        arr.reverse_each do |el|
            if r.children.has_key?(el)
               r = r.children[el]
                return true if r.end
            else
               break
            end
        end
        false
    end    
end




class StreamChecker

=begin
    :type words: String[]
=end
    def initialize(words)
        @trie = Trie.new
        words.each do |w|
           @trie.add(w) 
        end
        @queries = []
    end


=begin
    :type letter: Character
    :rtype: Boolean
=end
    def query(letter)
        @queries << letter
        @queries = @queries.first(2000)
        @trie.search(@queries)
    end


end
