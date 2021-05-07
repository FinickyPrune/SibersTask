//
//  EditorViewModel.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation

protocol EditorViewModelDelegate: class {
    func didSubmitValue(_ seder: EditorViewModel, value: String)
}


class EditorViewModel {
    weak var delegate: EditorViewModelDelegate?
    let string: String?
    
    init(_ value: String?) {
        string = value
    }
    
    func manageNewValue(_ value: String) {
        delegate?.didSubmitValue(self, value: value)
    }
}
