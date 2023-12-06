#g++  -o test_graph -I .\out .\main.cpp
g++ --std=c++17 .\Digraph\main.cpp -o .\Digraph\\out\\test_graph -std=c++17   

Write-Host "Compiled and running..."
Write-Host ""
Write-Host "-------START--------"
.\Digraph\out\test_graph.exe

Write-Host ""
Write-Host "--------END---------"
Write-Host ""
# move all dot files into out/graphs folder
# if files already exist, overwrite them

#Write-Host "Moving all dot files into out/graphs folder..."
#Move-Item .\*.dot .\Digraph\out\graphs
Write-Host "Done."

