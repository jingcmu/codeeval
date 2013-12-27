=begin
 Sample code to read in test cases:
File.open(ARGV[0]).each_line do |line|
# Do something with line, ignore empty lines
#...
end
=end

def count_ways(n)
	ways = [1, 2, 0]
	return $way[n-1] if n<=2 
	3.upto(n) do 
		ways[2] = ways[1] + ways[0]
		ways[0] = ways[1]
		ways[1] = ways[2]	
	end
	ways[2]
end

File.open(ARGV[0]).map(&:to_i).each do |n|
	puts count_ways(n)
end