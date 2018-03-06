import operator
graph = {'Oradea':{'Zerind':71,'Sibiu':151},'Zerind':{'Oradea':71,'Arad':75},'Arad':{'Zerind':75,'Timisoara':118,'Sibiu':140},'Timisoara':{'Arad':118,'Lugoj':111},'Lugoj':{'Timisoara':111,'Mehadia':70},'Mehadia':{'Lugoj':70,'Dobreta':70},'Dobreta':{'Mehadia':75,'Craiova':120},'Craiova':{'Dobreta':120,'Rimnicu Vilcea':146,'Pitesti':138},'Sibiu':{'Arad':140,'Oradea':151,'Rimnicu Vilcea':80,'Fagaras':99},'Rimnicu Vilcea':{'Sibiu':80,'Craiova':146,'Pitesti':97},'Fagaras':{'Sibiu':99,'Bucharest':221},'Pitesti':{'Bucharest':101,'Rimnicu Vilcea':97,'Craiova':138},'Bucharest':{'Fagaras':211,'Pitesti':101,'Giurgiu':90,'Urziceni':85},'Giurgiu':{'Bucharest':90},'Urziceni':{'Bucharest':85,'Hirsova':98,'Vaslui':142},'Hirsova':{'Urziceni':98,'Eforie':86},'Eforie':{'Hirsova':86},'Vaslui':{'Urziceni':142,'Iasi':92},'Iasi':{'Neamt':87,'Vaslui':92},'Neamt':{'Iasi':87}}
hsld = {'Arad':366, 'Bucharest':0, 'Craiova':160, 'Dobreta':242, 'Eforie':161, 'Fagaras':176, 'Giurgiu':77, 'Hirsova':151, 'Iasi':226, 'Lugoj':244, 'Mehadia':241, 'Neamt':234, 'Oradea':380, 'Pitesti':100, 'Rimnicu Vilcea':193, 'Sibiu':253, 'Timisoara':329, 'Urziceni':80, 'Vaslui':199, 'Zerind':374}

fn = sorted(hsld.items(), key=operator.itemgetter(1))

rechable_cities = [('Arad', 0)]
current_city = 'Arad'
path = ['Arad']
total_cost = 0
destination = 'Bucharest'

class Node:
    def __init__(self):
        self.name = ''
        self.distance_from_src = 0
        self.parent = ''
        self.rechable_cities = []
        
# build dict for all nodes
cities = {}
for city in list(graph.keys()):
    c = Node()
    c.name = city
    c.distance_from_src = 0
    c.parent='None'
    c.rechable_cities = []
    
    cities[city] = c
    
current_city = cities['Arad']

heuristic_results = []
ans = 0


while True:
    # fund current city
#    current_city = Node()
#    current_city.name = rechable_cities[0][0]
#    current_city.distance_from_src = rechable_cities[0][1]
    
    if current_city.name == destination:
        break
    
    # removing this city
#    rechable_cities = rechable_cities[1:]
    
    
    current_city.rechable_cities = list(graph[current_city.name].keys())
    
    for city in current_city.rechable_cities:
        distance = graph[current_city.name][city]
        #rechable_cities.append((current_city.name, current_city.distance_from_src + distance))  
        heuristic_results.append((city, current_city.distance_from_src + distance+hsld[city])) 
        cities[city].distance_from_src = current_city.distance_from_src + distance
        
        
    # Sort rechable citied
    heuristic_results = sorted(heuristic_results, key=operator.itemgetter(1))
    current_city = cities[heuristic_results[0][0]]
    heuristic_results = heuristic_results[1:]
    
    
    ans = current_city.distance_from_src
    print(current_city.name, ans)
    