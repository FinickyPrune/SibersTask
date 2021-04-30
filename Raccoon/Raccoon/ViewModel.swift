
class ViewModel {
    
    private var tableData: [Int] = []
    
    init() {
        tableData = (0..<100).map{_ in Int.random(in: 0..<100)}
    }
    
    public func getDataArraySize() -> Int{
        return tableData.count
    }
    
    public func getStringValue(at index: Int) -> String {
        return String(tableData[index])
    }
    
}
