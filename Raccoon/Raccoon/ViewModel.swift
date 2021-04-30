
class ViewModel {
    
    private(set) var tableData: [Int] = []
    
    init() {
        tableData = (0..<100).map{_ in Int.random(in: 0..<100)}
    }
    
    public func getStringValue(at index: Int) -> String {
        return String(tableData[index])
    }
    
    public func insertCellInData(at index: Int, with value: Int){
        tableData.insert(value, at: index)
    }
    
    public func deleteCellFromData(at index: Int){
        tableData.remove(at: index)
    }
    
    public func updateCellInData(at index: Int, with value: Int){
        tableData[index] = value
    }
    
}
