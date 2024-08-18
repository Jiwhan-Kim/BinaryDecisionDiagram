from graphviz import Digraph

# 파일 경로
file_path = '../Submit/ReducedBDD/output_S1.txt'

outputFileName = file_path.split('/')[-1].split('.')[0]

# 파일 열기 및 내용 읽기
try:
  with open(file_path, 'r') as file:
    content = file.read()
except FileNotFoundError:
  print(f"파일을 찾을 수 없습니다: {file_path}")
except IOError as e:
  print(f"파일을 읽는 중 오류가 발생했습니다: {e}")

informations = content.split('\n')

totalVariables = 0
totalNodes = 0
totalTreeNodes = 0
treeNodes = []

for information in informations:
  if information == '':
    continue
  
  order = information.split(' ')

  category = order[0]
  node = order[1]

  if category == 'TotalVariables':
    totalVariables = int(node)
  elif category == 'TotalNodes':
    totalNodes = int(node)
  elif category == 'TotalTreeNodes':
    totalTreeNodes = int(node)
  else:
    treeNodes.append(node)

g = Digraph()

for (index, node) in enumerate(treeNodes):
  if node == 'X':
    continue
  g.node(node + str(index), node)

for (index, node) in enumerate(treeNodes):
  if node == 'X':
    continue

  if index * 2 + 1 >= totalTreeNodes:
    continue

  leftIndex = index * 2 + 1
  rightIndex = index * 2 + 2

  left = treeNodes[leftIndex]
  right = treeNodes[rightIndex]

  if left != 'X':
    g.edge(node + str(index), left + str(leftIndex), color='green')

  if right != 'X':
    g.edge(node + str(index), right + str(rightIndex), color='red')

g.render(outputFileName, format='jpeg', cleanup=False)

  



"""
# Digraph 객체 생성
g = Digraph()

# 노드 추가
g.node('A', 'Start')
g.node('B', 'Process')
g.node('C', 'End')

# 엣지(간선) 추가
g.edge('A', 'B', 'Step 1')
g.edge('B', 'C', 'Step 2')

# 결과를 PDF 파일로 저장
g.render('example_graph', format='jpeg', cleanup=False)

# # 그래프를 보기 위해 PDF 파일 열기
# from IPython.display import display, Image
# display(Image(filename='example_graph.pdf'))
"""