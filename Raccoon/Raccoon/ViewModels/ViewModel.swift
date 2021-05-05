
import UIKit

protocol ViewModelDelegate: class {
    
    func deleteCell(sender: ViewModel, at index: Int)
    func updateCell(sender: ViewModel, at index: Int)
    func insertCell(sender: ViewModel, at index: Int)
    func createEditorController(sender: ViewModel, with value: Int?)

}


class ViewModel {
    
    weak var delegate: ViewModelDelegate?
    private var basicDataManager: DataManager = BasicDataManager()
    
    private var isEditing: Bool = false
    private var pressedCellIndex: Int?
    
    func getDataCount() -> Int {
        return basicDataManager.getDataCount()
    }
    
    func getStringValue(at index: Int) -> String {
        return basicDataManager.getStringValue(at: index)
    }
    
    func getPressedCellIndex() -> Int? {
        return pressedCellIndex
    }
    
    private func insertData(at index: Int, with value: Int) {
        basicDataManager.insertValue(value, at: index)
        delegate?.insertCell(sender: self, at: index)
    }
    
    func removeFromData(at index: Int) {
        basicDataManager.removeValue(at: index)
        delegate?.deleteCell(sender: self, at: index)
    }
    
    private func updateData(at index: Int, with value: Int) {
        basicDataManager.updateValue(for: value, at: index)
        delegate?.updateCell(sender: self, at: index)
    }
    
    func addButtonPressed() {
        isEditing = false
        delegate?.createEditorController(sender: self, with: nil)
    }
    
    func didSelectValue(at index: Int) {
        isEditing = true
        pressedCellIndex = index
        delegate?.createEditorController(sender: self, with: Int(basicDataManager.getStringValue(at: index)))
    }
    
    func didReceiveNewValue(_ value: Int) {
        if isEditing {
            guard let index = pressedCellIndex else {
                return
            }
            updateData(at: index, with: value)
        }
        else {
            insertData(at: 0, with: value)
        }
    }
    
}

