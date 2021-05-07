
import UIKit

protocol ViewModelDelegate: class {
    
    func deleteCell(sender: ViewModel, at index: Int)
    func updateCell(sender: ViewModel, at index: Int)
    func insertCell(sender: ViewModel, at index: Int)
    func createEditorController(sender: ViewModel, with value: String?)
}


class ViewModel {
    
    weak var delegate: ViewModelDelegate?
    private var dataManager: DataManager = NetworkDataManager()
    
    private var isEditing: Bool = false
    private var pressedCellIndex: Int?
    
    func getDataCount() -> Int {
        return dataManager.getDataCount()
    }
    
    func getStringValue(at index: Int) -> String {
        return dataManager.getStringValue(at: index)
    }
    
    func getPressedCellIndex() -> Int? {
        return pressedCellIndex
    }
    
    private func insertData<T>(at index: Int, with value: T) {
        dataManager.insertValue(value, at: index)
        delegate?.insertCell(sender: self, at: index)
    }
    
    func removeFromData(at index: Int) {
        dataManager.removeValue(at: index)
        delegate?.deleteCell(sender: self, at: index)
    }
    
    private func updateData<T>(at index: Int, with value: T) {
        dataManager.updateValue(for: value, at: index)
        delegate?.updateCell(sender: self, at: index)
    }
    
    func fetchData(_ completion: @escaping () -> Void) {
        dataManager.loadData() {
            completion()
        }
    }
    
    func addButtonPressed() {
        isEditing = false
        delegate?.createEditorController(sender: self, with: nil)
    }
    
    func didSelectValue(at index: Int) {
        isEditing = true
        pressedCellIndex = index
        delegate?.createEditorController(sender: self, with: dataManager.getStringValue(at: index))
    }
    
    func didReceiveNewValue(_ value: String) {
        
        var typedValue: Any? = nil
        
        if  let _ = dataManager as? BasicDataManager {
            typedValue = Int(value)
        }
        else if let _ = dataManager as? NetworkDataManager {
            typedValue = String(value)
        }
        if isEditing {
            guard let index = pressedCellIndex else {
                return
            }
            updateData(at: index, with: typedValue)
        }
        else {
            insertData(at: 0, with: typedValue)
        }
    }
    
}

