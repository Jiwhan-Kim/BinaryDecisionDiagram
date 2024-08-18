from graphviz import Digraph

def makeGraphToImage(input_file_path, output_file_path):

  # 파일 경로
  # file_path = '../Submit/ReducedBDD/output_S1.txt'

  file_path = input_file_path

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

  g.render(output_file_path , format='jpeg', cleanup=False)

makeGraphToImage('./output/Carry.txt', './output/Carry')
makeGraphToImage('./output/S0.txt', './output/S0')
makeGraphToImage('./output/S1.txt', './output/S1')
makeGraphToImage('./output/S2.txt', './output/S2')
makeGraphToImage('./output/S3.txt', './output/S3')

